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
    for(int i=INIT; i<CONSOLE_LENGTH; i++)
    {
        if (c.GetFirst()==NULL||aliens.GetFirst()==NULL)
            return;

        c.SetIter();
        while (c.GetIter() != NULL)
        {
            if (i == c.GetIter()->GetColumn())
                break;

            else
                c.NextBullet();
        }

        aliens.SetIter();
        while (aliens.GetIter() != NULL)
        {
            if (i == aliens.GetIter()->GetColumn())
                break;

            else
                aliens.NextEnemy();
        }

        if (c.GetIter()->GetRow() == aliens.GetIter()->GetRow())
        {
          /*  c.RemoveObject(c.GetIter());
            if (aliens.GetIter()->CheckDie())
                aliens.RemoveEnemy(aliens.GetIter());*/
        }
        /*
        while (c.GetIter()!= NULL)
        {
            if (i == c.GetIter()->GetColumn())
            {
                alliens.SetIter();
                while (alliens.GetIter()!= NULL)
                {

                    if((c.GetIter()->GetColumn() == alliens.GetIter()->GetColumn())&&(c.GetIter()->GetRow() == alliens.GetIter()->GetRow()))
                    {

                        c.RemoveObject(c.GetIter());
                        if (alliens.GetIter()->CheckDie())
                        {
                            alliens.RemoveEnemy(alliens.GetIter());
                        }
                    }
                    alliens.NextEnemy();
                }
            }
            c.NextBullet();
        }*/
    }
}

//Controlla se la navicella del giocatore ha avuto una collisione con il nemico
void Game::Collision()
{
    //TO DO
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
