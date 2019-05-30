/**********************************************************
* File Game.cpp                                           *
* Contiene l'implementazione dei metodi della classe Game *
**********************************************************/

#include "Game.h"

//Costruttore
Game::Game()
{
    score = INIT;
    highScore = INIT;

    //Disegno la finestra principale
    main_win.PrintWinBorder();
    Banner();
    wrefresh(main_win.GetWin());

    start_message = new Window(main_win.GetWin(),22, 12, 60, 5);

    StartMessage();
    start_message->PrintWinBorder();
    wrefresh(start_message->GetWin());

    //Apro la finestra di gioco
    game_win = new Window(main_win.GetWin());
}

//Messaggio iniziale
void Game::StartMessage()
{
    wprintw(start_message->GetWin(), "\n\tGuerriero Spaziale benvenuto in Invasions\n   Difendi l'universo dagli alieni e conquista la gloria\n\t\t     COSA ASPETTI!!!");
}

//Banner iniziale
void Game::Banner()
{
    mvwprintw(main_win.GetWin(), 1, START_XY, "\t  _________ _                 _______  _______ _________ _______  _        _______");
    mvwprintw(main_win.GetWin(), 2, START_XY, "\t  \\__   __/( (    /||\\     /|(  ___  )(  ____ \\\\__   __/(  ___  )( (    /|(  ____ \\");
    mvwprintw(main_win.GetWin(), 3, START_XY, "\t     ) (   |  \\  ( || )   ( || (   ) || (    \\/   ) (   | (   ) ||  \\  ( || (    \\/");
    mvwprintw(main_win.GetWin(), 4, START_XY, "\t     | |   |   \\ | || |   | || (___) || (_____    | |   | |   | ||   \\ | || (_____ ");
    mvwprintw(main_win.GetWin(), 5, START_XY, "\t     | |   | (\\ \\) |( (   ) )|  ___  |(_____  )   | |   | |   | || (\\ \\) |(_____  )");
    mvwprintw(main_win.GetWin(), 6, START_XY, "\t     | |   | | \\   | \\ \\_/ / | (   ) |      ) |   | |   | |   | || | \\   |      ) |");
    mvwprintw(main_win.GetWin(), 7, START_XY, "\t  ___) (___| )  \\  |  \\   /  | )   ( |/\\____) |___) (___| (___) || )  \\  |/\\____) |");
    mvwprintw(main_win.GetWin(), 8, START_XY, "\t  \\_______/|/    )_)   \\_/   |/     \\|\\_______)\\_______/(_______)|/    )_)\\_______)");
}

//Stampa a video la condizione attuale della partita
void Game::UpdateScreen()
{
    //Disegno la finestra di gioco
    game_win->PrintWinBorder();

    //stampa i colpi sparati dalla navicella del giocatore
    c.Draw(game_win->GetWin());

    //Stampa i nemici
    aliens.Draw(game_win->GetWin());

    //Stampa la navicella del giocatore
    player.Draw(game_win->GetWin());

    //Aggiorno la finestra di gioco
    wrefresh(game_win->GetWin());
}

//Gestisce l'input per lo spastamento della navicella del giocatore
bool Game::MoveSpacesraft()
{
    //Legge l'input da tastiera
    int key = getch();

    //Chiama la funzione per muovere la navicella e controlla se e' stato digitato q
    if (!player.Move(key))
        return TRUE;

    return FALSE;
}

//Sparo della navicella del giocatore
void Game::SpacecraftShoot()
{
    player.Shoot(c);
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

//Generazione dei nemici
void Game::GenerationEnemy()
{
    aliens.AddEnemy();
}

//Per lo spostamento dei nemici
void Game::MoveEnemy()
{
    aliens.MoveEnemy();
}

//Controlla se � stato colpito il nemico
void Game::EnemyHitted()
{
    //Scansiona tutti i nemici
    for (aliens.SetIter(); aliens.GetIter()!= NULL; aliens.NextEnemy())
    {
        //Scanziona tutti i colpi
        for (c.SetIter(); c.GetIter()!= NULL; c.NextBullet())
        {
            //Controllo se il colpo � stato sparato dal giocatore
            if (c.GetIter()->GetId() == PLAYER)
            {
                //Confronto le coordinate del colpo con quelle del nemico
                if((c.GetIter()->GetRow() == aliens.GetIter()->GetRow()) && ((c.GetIter()->GetColumn() == aliens.GetIter()->GetColumn()) || (c.GetIter()->GetColumn() == aliens.GetIter()->GetColumn()-1) || (c.GetIter()->GetColumn() == aliens.GetIter()->GetColumn()+1)))
                {
                    //Cancello il colpo
                    c.RemoveObject(c.GetIter());

                    //Controllo se il nemico � morto
                    if (aliens.GetIter()->CheckDie())
                    {
                        aliens.RemoveEnemy(aliens.GetIter());
                    }
                }
            }
        }
    }
}

//Controlla se � stato colpito il giocatore
void Game::PlayerHitted()
{
    //Scanziona tutti i colpi
    for (c.SetIter(); c.GetIter()!= NULL; c.NextBullet())
    {
        //Controllo se il colpo � stato sparato dal nemico
        if (c.GetIter()->GetId() == ENEMY)
        {
            //Confronto le coordinate del colpo con quelle della namicella
            if((c.GetIter()->GetRow() == player.GetRow()) && ((c.GetIter()->GetColumn() == player.GetColumn()) || (c.GetIter()->GetColumn() == player.GetColumn()-1) || (c.GetIter()->GetColumn() == player.GetColumn()-2) || (c.GetIter()->GetColumn() == player.GetColumn()+1) || (c.GetIter()->GetColumn() == player.GetColumn()+2)))
            {
                //Cancello il colpo
                c.RemoveObject(c.GetIter());

                //Controllo se la navicella del giocatore � morta
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
    //Controllo se c'� stata una collisione tra il nemico e la navicella
    for(aliens.SetIter(); aliens.GetIter()!= NULL; aliens.NextEnemy())
    {
        if (((player.GetRow() == aliens.GetIter()->GetRow()) && ((player.GetColumn() == aliens.GetIter()->GetColumn()) || (player.GetColumn() == aliens.GetIter()->GetColumn()-1) || (player.GetColumn() == aliens.GetIter()->GetColumn()+1) || (player.GetColumn()-2 == aliens.GetIter()->GetColumn()) || (player.GetColumn()-2 == aliens.GetIter()->GetColumn()+1) || (player.GetColumn()+2 == aliens.GetIter()->GetColumn()) || (player.GetColumn()+2 == aliens.GetIter()->GetColumn()-1))))
        {
            aliens.RemoveEnemy(aliens.GetIter());
            if(player.DecreseLife(ENEMY_LIFE))
            {
                mvprintw(GAME_WIN_HIGH/2,43,"SEI MORTO");
                refresh();
                delay_output(5000);
                exit(0);
            }
        }
    }
}

//Aggiora il punteggio
void Game::UpdateScore()
{
    //TO DO
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

//Distruttore
Game::~Game()
{
    delete start_message;
    delete game_win;
}
