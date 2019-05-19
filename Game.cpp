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
}

//Messaggio iniziale
void Game::StartMessage()
{
    //TO DO
}

//Stampa a video la condizione attuale della partita
void Game::UpdateScreen()
{
    //Cancella la schermata
    erase();

    //Stampa i nemici
    aliens.Draw();

    //Stampa la navicella del giocatore
    player.Draw();

    //stampa i colpi sparati dalla navicella del giocatore
    c.Draw();

    refresh();
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

//Generazione dei nemici
void Game::GenerationEnemy()
{
    //Controllo se possono essere generati i nemici
    if (ENEMY_GENERATION_TIME)
        aliens.AddEnemy();
}

//Per lo spostamento dei nemici
void Game::MoveEnemy()
{
    aliens.MoveEnemy();
}

//Controlla se è stato colpito il nemico
void Game::Hitted()
{
    for (aliens.SetIter(); aliens.GetIter()!= NULL; aliens.NextEnemy())
    {
        for (c.SetIter(); c.GetIter()!= NULL; c.NextBullet())
        {
            if((c.GetIter()->GetRow()+1 == aliens.GetIter()->GetRow()) && ((c.GetIter()->GetColumn() == aliens.GetIter()->GetColumn()+1) || (c.GetIter()->GetColumn() == aliens.GetIter()->GetColumn()) || (c.GetIter()->GetColumn() == aliens.GetIter()->GetColumn()+2)))
            {
                c.RemoveObject(c.GetIter());
                if (aliens.GetIter()->CheckDie())
                {
                    aliens.RemoveEnemy(aliens.GetIter());
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
        if ((player.GetRow() == aliens.GetIter()->GetRow()-1) && (player.GetColumn() == aliens.GetIter()->GetColumn()+1))
        {
            aliens.RemoveEnemy(aliens.GetIter());
            if(player.DecreseLife(ENEMY_LIFE))
            {
                mvprintw(CONSOLE_HIGH/2,43,"SEI MORTO");
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
