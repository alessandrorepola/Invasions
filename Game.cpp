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

    //Apro la finestra di gioco
    game_win = new Window(main_win.GetWin());
}

//Messaggio iniziale
void Game::StartMessage()
{
    //TO DO
}

//Stampa a video la condizione attuale della partita
void Game::UpdateScreen()
{
    game_win->PrintWinBorder();

    //stampa i colpi sparati dalla navicella del giocatore
    c.Draw(game_win->GetWin());

    //Stampa i nemici
    aliens.Draw(game_win->GetWin());

    //Stampa la navicella del giocatore
    player.Draw(game_win->GetWin());

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
    delete game_win;
}
