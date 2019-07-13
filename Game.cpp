/**********************************************************
* Game.cpp                                                *
* Contiene l'implementazione dei metodi della classe Game *
**********************************************************/

#include "Game.h"

//Costruttore
Game::Game()
{
    score = INIT;

//    SetBestScore();

    //Dichiaro una finestra di gioco
    game_win = new Window(main_win.GetWin());

    //Dichiaro una finestra per la visualizzazione del punteggio
    score_win = new Window(main_win.GetWin(), game_win->GetX(), game_win->GetHeight()+START_XY, game_win->GetWidth()/2, main_win.GetHeight()-game_win->GetHeight()-2);

    //dichiaro una finestra per la visualizzazione della vita
    life_win = new Window(main_win.GetWin(), score_win->GetWidth()+START_XY, score_win->GetY(), score_win->GetWidth()+1, score_win->GetHeight());
}

//Stampa a video l'Help
void Game::Help(Window &parent)
{
    Window help(parent.GetWin(), parent.GetWidth()/4, parent.GetHeight()/4, parent.GetWidth()/2, parent.GetHeight()/2);
    werase(parent.GetWin());
    wattrset(help.GetWin(), COLOR_PAIR(CYAN));
    wprintw(help.GetWin(), "\n                  Comandi di gioco\n");
    wprintw(help.GetWin(), "\n      Comando                     Tasto\n");
    wattrset(help.GetWin(), COLOR_PAIR(WHITE));
    wprintw(help.GetWin(), "\n      Sopra:                        "); waddch(help.GetWin(),ACS_UARROW);
    wprintw(help.GetWin(), "\n      Sotto:                        "); waddch(help.GetWin(),ACS_DARROW);
    wprintw(help.GetWin(), "\n      Destra:                       "); waddch(help.GetWin(),ACS_RARROW);
    wprintw(help.GetWin(), "\n      Sinistra:                     "); waddch(help.GetWin(),ACS_LARROW);
    wprintw(help.GetWin(), "\n      Pausa:                        p");
    wprintw(help.GetWin(), "\n      Esci:                         q");
    wattrset(help.GetWin(), COLOR_PAIR(CYAN));
    wprintw(help.GetWin(), "\n\n                  Comandi del menu\n");
    wattrset(help.GetWin(), COLOR_PAIR(WHITE));
    wprintw(help.GetWin(), "\n      Voce Precedente:              "); waddch(help.GetWin(),ACS_UARROW);
    wprintw(help.GetWin(), "\n      Voce Successiva:              "); waddch(help.GetWin(),ACS_DARROW);
    wprintw(help.GetWin(), "\n      Scegli:                     Enter");

    help.PrintWinBorder();
    parent.PrintWinBorder();
    wattrset(parent.GetWin(), COLOR_PAIR(BLUE));
    mvwprintw(parent.GetWin(), 9, 30, " GUIDA ");
    wattrset(parent.GetWin(), COLOR_PAIR(WHITE));
    wrefresh(parent.GetWin());
    getchar();
}

//Per la scelta dell'utente
void Game::UserChoice(int choice)
{
    switch(choice)
    {
        case NEW_MATCH:
            break;

        case LAST_MATCH:
//            ResumeLastMatch();
            break;

        case HELP:
            Help(GetMainWin());
            MainScreen();
            break;

        case EXIT:
            BulletList.DeleteList();
            EnemyList.DeleteList();
            endwin();
            exit(INIT);
    }
}

//Schermata principale
void Game::MainScreen()
{
    werase(main_win.GetWin());

    //Disegno la finestra principale
    main_win.PrintWinBorder();
    Banner();
    wrefresh(main_win.GetWin());

    //Messaggio iniziale
    StartMessage();

    //Menu principale
    Menu menu(GetMainWin());
    UserChoice(menu.GetChoice());
}

//Loop principale del gioco
bool Game::StartGameLoop()
{
    while (true)
    {
        //Sposta la nevicella del giocatore
        switch (UserInput())
        {
            case RESTART:
                return true;

            case MAIN_MENU:
//                SaveBestScore();
//                SaveGameStatus();
                BulletList.DeleteList();
                EnemyList.DeleteList();
                return false;

            case EXIT:
//                SaveBestScore();
//                SaveGameStatus();
                BulletList.DeleteList();
                EnemyList.DeleteList();
                endwin();
                exit(INIT);
        }

        //Sposta la navicella del giocatore
        player.Move();

        //Sparo del giocatore
        player.Shoot(BulletList);

        //Sparo del nemico
        //aliens.EnemyShoot(BulletList);

        //Sposta gli alieni
        EnemyList.Move();

        //Controlla se il nemico è stato colpito
//        EnemyHitted();

        //Controlla se il nemico è stato colpito
//        PlayerHitted();

        /*PROVVISORIO*/
        //Generazione dei nemici
        ep = new Enemy;
        EnemyList.Add(ep, ep->GetGenerationTime());

        //Aggiorno la schermata
        UpdateScreen();

        //Contrlla se c'è stata una collisione tra il nemico e la navicella
//        Collision();

        //Rallento l'esecuzione del loop per evitare un utilizzo intenso della CPU
        usleep(1);
    }
    return false;
}

//Messaggio iniziale
void Game::StartMessage()
{
    start_message = new Window(main_win.GetWin(), 22, 12, 60, 5);
    wprintw(start_message->GetWin(), "\n\tGuerriero Spaziale benvenuto in Invasions\n   Difendi l'universo dagli alieni e conquista la gloria\n\t\t     COSA ASPETTI!!!");
    start_message->PrintWinBorder();
    wrefresh(start_message->GetWin());
    delete start_message;
}

//Banner iniziale
void Game::Banner()
{
    wattron(main_win.GetWin(),COLOR_PAIR(ORANGE));
    mvwprintw(main_win.GetWin(), 1, START_XY, "\t  _________ _                 _______  _______ _________ _______  _        _______");
    mvwprintw(main_win.GetWin(), 2, START_XY, "\t  \\__   __/( (    /||\\     /|(  ___  )(  ____ \\\\__   __/(  ___  )( (    /|(  ____ \\");
    mvwprintw(main_win.GetWin(), 3, START_XY, "\t     ) (   |  \\  ( || )   ( || (   ) || (    \\/   ) (   | (   ) ||  \\  ( || (    \\/");
    mvwprintw(main_win.GetWin(), 4, START_XY, "\t     | |   |   \\ | || |   | || (___) || (_____    | |   | |   | ||   \\ | || (_____ ");
    mvwprintw(main_win.GetWin(), 5, START_XY, "\t     | |   | (\\ \\) |( (   ) )|  ___  |(_____  )   | |   | |   | || (\\ \\) |(_____  )");
    mvwprintw(main_win.GetWin(), 6, START_XY, "\t     | |   | | \\   | \\ \\_/ / | (   ) |      ) |   | |   | |   | || | \\   |      ) |");
    mvwprintw(main_win.GetWin(), 7, START_XY, "\t  ___) (___| )  \\  |  \\   /  | )   ( |/\\____) |___) (___| (___) || )  \\  |/\\____) |");
    mvwprintw(main_win.GetWin(), 8, START_XY, "\t  \\_______/|/    )_)   \\_/   |/     \\|\\_______)\\_______/(_______)|/    )_)\\_______)");
    wattrset(main_win.GetWin(),COLOR_PAIR(WHITE));
}

//Stampa a video la condizione attuale della partita
void Game::UpdateScreen()
{
    //Disegno la finestra di gioco
    game_win->PrintWinBorder();
    main_win.PrintWinBorder();
    PrintLife();

    //Stampo il punteggio
    PrintScore();

    //stampa i colpi sparati dalla navicella del giocatore
    BulletList.Draw(game_win->GetWin());

    //Stampa i nemici
    EnemyList.Draw(game_win->GetWin());

    //Stampa la navicella del giocatore
    player.Draw(game_win->GetWin());

    //Aggiorno la finestra di gioco
    wrefresh(main_win.GetWin());
}

//Gestisce l'input per lo spastamento della navicella del giocatore
int Game::UserInput()
{
    //Legge l'input da tastiera
    int key = getch();

    switch (key)
    {
        //tasti direzionali
        case KEY_UP:
        player.DecreaseRow();
        break;

        case KEY_DOWN:
        player.IncreaseRow();
        break;

        case KEY_LEFT:
        player.DecreaseColumn();
        break;

        case KEY_RIGHT:
        player.IncreaseColumn();
        break;

        case 'q':
        case 'Q':
            return EXIT;

        case 'p':
        case 'P':
        {
            Menu secondary_menu(*game_win);
            return secondary_menu.GetChoice();
        }

        // Se non viene premuto nessun tasto o un altro tasto diverso dai precedenti ritorana al loop principale
        case ERR:
        default:
            break;
    }
    return 0;
}

//Controlla se è stato colpito il nemico
/*void Game::EnemyHitted()
{
    //Scansiona tutti i nemici
    for (aliens.SetIter(); aliens.GetIter()!= NULL; aliens.NextEnemy())
    {
        //Scanziona tutti i colpi
        for (BulletList.SetIter(); BulletList.GetIter()!= NULL; BulletList.Next())
        {
            //Controllo se il colpo è stato sparato dal giocatore
            if (.GetIter()->GetId() == PLAYER)
            {
                //Confronto le coordinate del colpo con quelle del nemico
                if((c.GetIter()->GetRow() == aliens.GetIter()->GetRow()) && ((c.GetIter()->GetColumn() == aliens.GetIter()->GetColumn()) || (c.GetIter()->GetColumn() == aliens.GetIter()->GetColumn()-1) || (c.GetIter()->GetColumn() == aliens.GetIter()->GetColumn()+1)))
                {
                    //Cancello il colpo
                    c.RemoveObject(c.GetIter());

                    //Controllo se il nemico è morto
                    if (aliens.GetIter()->CheckDie())
                    {
                        aliens.RemoveEnemy(aliens.GetIter());
                        UpdateScore(20);
                        break;
                    }
                }
            }
        }
    }
}

//Controlla se è stato colpito il giocatore
void Game::PlayerHitted()
{
    //Scanziona tutti i colpi
    for (c.SetIter(); c.GetIter()!= NULL; c.NextBullet())
    {
        //Controllo se il colpo è stato sparato dal nemico
        if (c.GetIter()->GetId() == ENEMY)
        {
            //Confronto le coordinate del colpo con quelle della namicella
            if((c.GetIter()->GetRow() == player.GetRow()) && ((c.GetIter()->GetColumn() == player.GetColumn()) || (c.GetIter()->GetColumn() == player.GetColumn()-1) || (c.GetIter()->GetColumn() == player.GetColumn()-2) || (c.GetIter()->GetColumn() == player.GetColumn()+1) || (c.GetIter()->GetColumn() == player.GetColumn()+2)))
            {
                //Cancello il colpo
                c.RemoveObject(c.GetIter());

                life_win->PrintWinBorder();

                //Controllo se la navicella del giocatore è morta
                if (player.DecreaseLife(BULLET_DAMAGE))
                {
                    UpdateScreen();
                    mvprintw(GAME_WIN_HEIGHT/2,43,"SEI MORTO");
                    refresh();
                    delay_output(5000);
                    exit(0);
                }
            }
        }
    }
}

//Controlla se la navicella del giocatore ha avuto una collisione con il nemico
void Game::Collision()
{
    //Controllo se c'è stata una collisione tra il nemico e la navicella
    for(aliens.SetIter(); aliens.GetIter()!= NULL; aliens.NextEnemy())
    {
        if (((player.GetRow() == aliens.GetIter()->GetRow()) && ((player.GetColumn() == aliens.GetIter()->GetColumn()) || (player.GetColumn() == aliens.GetIter()->GetColumn()-1) || (player.GetColumn() == aliens.GetIter()->GetColumn()+1) || (player.GetColumn()-2 == aliens.GetIter()->GetColumn()) || (player.GetColumn()-2 == aliens.GetIter()->GetColumn()+1) || (player.GetColumn()+2 == aliens.GetIter()->GetColumn()) || (player.GetColumn()+2 == aliens.GetIter()->GetColumn()-1))))
        {
            //Controllo i punti vita rimasti alla navicella del giocatore
            if(player.DecreaseLife(aliens.GetIter()->GetLife()))
            {
                //Rimuovo il nemico
                aliens.RemoveEnemy(aliens.GetIter());

                UpdateScreen();
                mvprintw(GAME_WIN_HEIGHT/2,43,"SEI MORTO");
                refresh();
                delay_output(5000);
                exit(0);
            }
            else
            {
                //Rimuovo il nemico
                aliens.RemoveEnemy(aliens.GetIter());
            }

            //Aggiorno il punteggio
            UpdateScore(10);
        }
    }
}

//Aggiora il punteggio
void Game::UpdateScore(int value)
{
    score = score + value;
    if (score > bestScore)
    {
        bestScore = score;
    }
}

//Salva il miglior punteggio
void Game::SaveBestScore()
{
    f.Create();
    f.WriteBestScore(bestScore);
}

//Inizializza la variabile highScore
void Game::SetBestScore()
{
    //Controllo che i file esistono
    if(!f.Exists())
    {
        bestScore = INIT;
    }
    else
    {
        bestScore = f.ReadBestScore();
    }
}

//Salva lo stato attuale della partita
void Game::SaveGameStatus()
{
    f.WriteObj(c, aliens);
    f.WriteOtherInfo(player, score);
}

//Riprende la partita dal punto in cui è stata interrotta
void Game::ResumeLastMatch()
{
    f.ReadObj(&c, &aliens);
    f.ReadOtherInfo(&player, &score);
    UpdateScreen();
   // delay_output(2000);
}*/

//Restituisce un riferimento alla finestra principale
Window &Game::GetMainWin()
{
    return main_win;
}

//Inizializza il punteggio del giocatore
void Game::PrintScore()
{
    //Stampo i bordi della finestra
//    UpdateScore(INIT);
    werase(score_win->GetWin());
    wprintw(score_win->GetWin(), "\n Punteggio: %d",score);
    wprintw(score_win->GetWin(), "\n Record: %d",bestScore);
    score_win->PrintWinBorder();
}

//Inizializza la vita del giocatore
void Game::PrintLife()
{
    werase(life_win->GetWin());
    wprintw(life_win->GetWin(), "\n Punti vita: %d",player.GetLife());
    wprintw(life_win->GetWin(), "\n Scudo: %d",INIT);
    life_win->PrintWinBorder();
}

//Distruttore
Game::~Game()
{
    delete game_win;
    delete score_win;
    delete life_win;
}
