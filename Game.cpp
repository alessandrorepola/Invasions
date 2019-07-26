/**********************************************************
* Game.cpp                                                *
* Contiene l'implementazione dei metodi della classe Game *
**********************************************************/

#include "Game.h"

//Costruttore
Game::Game()
{
    score = INIT;

    SetBestScore();

    player = new Spacecraft(*game_win);

    //Finestra di gioco
    game_win = new Window(main_win.GetWin(), main_win.GetX(), main_win.GetY(), main_win.GetWidth()-(main_win.GetWidth()/6), main_win.GetHeight());

    //Finestra per la visualizzazione del punteggio
    info_win = new Window(main_win.GetWin(), game_win->GetWidth()+1, main_win.GetY(), main_win.GetWidth()/6, main_win.GetHeight());
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
                SaveBestScore();
//                SaveGameStatus();
                BulletList.DeleteList();
                EnemyList.DeleteList();
                return false;

            case EXIT:
                SaveBestScore();
//                SaveGameStatus();
                BulletList.DeleteList();
                EnemyList.DeleteList();
                endwin();
                exit(INIT);
        }

        //Sposta la navicella del giocatore
        player->Move(*game_win);

        //Sparo del giocatore
        player->Shoot(BulletList, *game_win);

        //Routine del nemico che comprende
        //Sparo
        //Spostamento
        EnemyRoutine();

        //Controlla se il nemico è stato colpito
        EnemyHitted();

        //Controlla se il nemico è stato colpito
        PlayerHitted();

        //Aggiorno la schermata
        UpdateScreen();

        //Contrlla se c'è stata una collisione tra il nemico e la navicella
        Collision();

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
    info_win->PrintWinBorder();
    main_win.PrintWinBorder();
    //PrintLife();

    //stampa i colpi sparati dalla navicella del giocatore
    BulletList.Draw(game_win->GetWin());

    //Stampa i nemici
    EnemyList.Draw(game_win->GetWin());

    //Stampa i colpi dei nemici
    EnemyBulletList.Draw(game_win->GetWin());

    //Stampa la navicella del giocatore
    player->Draw(game_win->GetWin());

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
        player->DecreaseRow();
        break;

        case KEY_DOWN:
        player->IncreaseRow();
        break;

        case KEY_LEFT:
        player->DecreaseColumn();
        break;

        case KEY_RIGHT:
        player->IncreaseColumn();
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

//Routine dei nemici per lo sparo e lo spostamento el la generazione
void Game::EnemyRoutine()
{
    //Genera un nuovo nemico
    Enemy *enemyp = new Enemy(*game_win);
    EnemyList.Add(enemyp, enemyp->GetGenerationTime());

    //Iterazioni su tutti gli oggetti della lista
    for (EnemyList.SetIter(); !EnemyList.EndList(); EnemyList.SetNext())
    {
        //Sparo
        EnemyList.GetEnemy()->Shoot(EnemyBulletList);  //Generazione del colpo
        for (EnemyBulletList.SetIter(); !EnemyBulletList.EndList(); EnemyBulletList.SetNext())
        {
            EnemyBulletList.GetBullet()->Move(*game_win);   //Spostamento di tutti i colpi sparati

            //Controlla se ci sono colpi da cancellare
            if (EnemyBulletList.GetBullet()->Remove(*game_win))
            {
                EnemyBulletList.Remove(EnemyBulletList.GetBullet());
            }
        }

        //Spostamento
        EnemyList.GetEnemy()->Move(*game_win);
    }

}

//Controlla se è stato colpito il nemico
void Game::EnemyHitted()
{
    //Scansiona tutti i nemici
    for (EnemyList.SetIter(); !EnemyList.EndList(); EnemyList.SetNext())
    {
        //Scanziona tutti i colpi
        for (BulletList.SetIter(); !BulletList.EndList(); BulletList.SetNext())
        {
            //Controllo se il colpo è stato sparato dal giocatore
            if (BulletList.GetIter()->GetDirection() == NORTH)
            {
                //Confronto le coordinate del colpo con quelle del nemico
                if((BulletList.GetIter()->GetRow() == EnemyList.GetIter()->GetRow()) &&
                   ((BulletList.GetIter()->GetColumn() == EnemyList.GetIter()->GetColumn()) ||
                    (BulletList.GetIter()->GetColumn() == EnemyList.GetIter()->GetColumn()-1) ||
                    (BulletList.GetIter()->GetColumn() == EnemyList.GetIter()->GetColumn()+1)))
                {
                    EnemyList.GetIter()->DecreaseLife(BulletList.GetIter()->GetLife());

                    //Cancello il colpo
                    BulletList.Remove(BulletList.GetIter());

                    //Controllo se il nemico è morto
                    if (EnemyList.GetIter()->GetLife() == 0)
                    {
                        EnemyList.Remove(EnemyList.GetIter());
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
    //Scanziona tutti i colpi nemici
    for (EnemyBulletList.SetIter(); !EnemyBulletList.EndList(); EnemyBulletList.SetNext())
    {
        //Confronto le coordinate del colpo con quelle della namicella
        if((EnemyBulletList.GetIter()->GetRow() == player->GetRow()) &&
            ((EnemyBulletList.GetIter()->GetColumn() == player->GetColumn()) ||
            (EnemyBulletList.GetIter()->GetColumn() == player->GetColumn()-1) ||
            (EnemyBulletList.GetIter()->GetColumn() == player->GetColumn()-2) ||
            (EnemyBulletList.GetIter()->GetColumn() == player->GetColumn()+1) ||
            (EnemyBulletList.GetIter()->GetColumn() == player->GetColumn()+2)))
        {
            //Cancello il colpo
            EnemyBulletList.Remove(EnemyBulletList.GetIter());

            //life_win->PrintWinBorder();

            player->DecreaseLife(BULLET_DAMAGE);

            //Controllo se la navicella del giocatore è morta
            if (player->GetLife() == 0)
            {
                UpdateScreen();
                mvprintw(30/2,43,"SEI MORTO");
                refresh();
                delay_output(5000);
                exit(0);
            }
        }
    }
}

//Controlla se la navicella del giocatore ha avuto una collisione con il nemico
void Game::Collision()
{
    //Controllo se c'è stata una collisione tra il nemico e la navicella
    for(EnemyList.SetIter(); !EnemyList.EndList(); EnemyList.SetNext())
    {
        if (((player->GetRow() == EnemyList.GetIter()->GetRow()) &&
             ((player->GetColumn() == EnemyList.GetIter()->GetColumn()) ||
              (player->GetColumn() == EnemyList.GetIter()->GetColumn()-1) ||
              (player->GetColumn() == EnemyList.GetIter()->GetColumn()+1) ||
              (player->GetColumn()-2 == EnemyList.GetIter()->GetColumn()) ||
              (player->GetColumn()-2 == EnemyList.GetIter()->GetColumn()+1) ||
              (player->GetColumn()+2 == EnemyList.GetIter()->GetColumn()) ||
              (player->GetColumn()+2 == EnemyList.GetIter()->GetColumn()-1))))
        {
            player->DecreaseLife(EnemyList.GetIter()->GetLife());

            //Rimuovo il nemico
            EnemyList.Remove(EnemyList.GetIter());

            //Controllo i punti vita rimasti alla navicella del giocatore
            if(player->GetLife() == 0)
            {
                UpdateScreen();
                mvprintw(30/2,43,"SEI MORTO");
                refresh();
                delay_output(5000);
                exit(0);
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
    //Controllo che i file esistano
    if(!f.Exists())
    {
        bestScore = INIT;
    }
    else
    {
        bestScore = f.ReadBestScore();
    }
}
/*
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
/*void Game::PrintScore()
{
    //Stampo i bordi della finestra
    UpdateScore(INIT);
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
}*/

//Distruttore
Game::~Game()
{
    delete game_win;
    delete info_win;
}
