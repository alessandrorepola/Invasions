/**********************************************************
* File Game.cpp                                           *
* Contiene l'implementazione dei metodi della classe Game *
**********************************************************/

#include "Game.h"

//Costruttore
Game::Game()
{
    score = INIT;

    //Disegno la finestra principale
    main_win.PrintWinBorder();
    Banner();
    wrefresh(main_win.GetWin());

    StartMessage();

    //Dichiaro una finestra di gioco
    game_win = new Window(main_win.GetWin());

    //Dichiaro una finestra per la visualizzazione del punteggio
    score_win = new Window(main_win.GetWin(),START_XY,32,30, 4);

    //dichiaro una finestra per la visualizzazione della vita
    life_win = new Window(main_win.GetWin(),START_XY+32,32,30, 4);
}

//Loop principale del gioco
int Game::StartGameLoop()
{
    int choice = EXIT;

    while (true)
    {
        //Sposta la nevicella del giocatore
        switch (UserInput())
        {
            case RESTART:
                choice = RESTART;
                break;

            case MAIN_MENU:
                choice = MAIN_MENU;
                break;

            case EXIT:
                exit(INIT);
        }

        if (choice == RESTART || choice == MAIN_MENU)
        {
            return choice;
        }

        //Sparo del giocatore
        player.Shoot(c);

        //Sparo del nemico
        EnemyShoot();

        //Sposta gli alieni
        aliens.MoveEnemy();

        //Controlla se il nemico è stato colpito
        EnemyHitted();

        //Controlla se il nemico è stato colpito
        PlayerHitted();

        //Generazione dei nemici
        aliens.AddEnemy();

        //Aggiorno la schermata
        UpdateScreen();

        //Contrlla se c'è stata una collisione tra il nemico e la navicella
        Collision();

        //Rallento l'esecuzione del loop per evitare un utilizzo intenso della CPU
        usleep(1);
    }
    return 0;
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
    c.Draw(game_win->GetWin());

    //Stampa i nemici
    aliens.Draw(game_win->GetWin());

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

    int value = player.Move(key, *game_win);

    //Chiama la funzione per muovere la navicella e controlla se e' stato digitato q
    if (value == 0)
        return 0;

    return value;
}

//Gestisce lo sparo dei nemici
void Game::EnemyShoot()
{
    for(aliens.SetIter(); aliens.GetIter()!= NULL; aliens.NextEnemy())
    {
        //Scelgo una navicella random da cui sparare
        if (rand()%12==0)
        {
            //Spara il colpo
            c.AddObject(aliens.GetIter()->GetRow()+1, aliens.GetIter()->GetColumn(), ENEMY);
            c.MoveObject();
        }
    }
}

//Controlla se è stato colpito il nemico
void Game::EnemyHitted()
{
    //Scansiona tutti i nemici
    for (aliens.SetIter(); aliens.GetIter()!= NULL; aliens.NextEnemy())
    {
        //Scanziona tutti i colpi
        for (c.SetIter(); c.GetIter()!= NULL; c.NextBullet())
        {
            //Controllo se il colpo è stato sparato dal giocatore
            if (c.GetIter()->GetId() == PLAYER)
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
                if (player.DecreseLife(BULLET_DAMAGE))
                {
                    mvprintw(GAME_WIN_HIGH/2,43,"SEI MORTO");
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
            //Rimuovo il nemico
            aliens.RemoveEnemy(aliens.GetIter());

            //Controllo i punti vita rimasti alla navicella del giocatore
            if(player.DecreseLife(aliens.GetIter()->GetLife()))
            {
                mvprintw(GAME_WIN_HIGH/2,43,"SEI MORTO");
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
    if (score > highScore)
    {
        highScore = score;
    }
}

//Salva il miglior punteggio
void Game::SaveScore()
{
    //TO DO
}

//Inizializza la variabile highScore
void Game::ReadHighScore()
{
    //TO DO
}

void SaveGame()
{
    scr_init("Salva_Schermo.bin");
}

//Restituisce un riferimento alla finestra principale
Window &Game::GetMainWin()
{
    return main_win;
}

//Inizializza il punteggio del giocatore
void Game::PrintScore()
{
    //Stampo i bordi della finestra
    UpdateScore(INIT);
    werase(score_win->GetWin());
    wprintw(score_win->GetWin(), "\n Punteggio: %d",score);
    wprintw(score_win->GetWin(), "\n Record: %d",highScore);
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
