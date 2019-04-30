/********************************************************************************************************
* File Game.h                                                                                           *
* Contiene la classe Game che gestisce gli oggetti del gioco come la navicella, i nemici, i colpi, ecc. *
********************************************************************************************************/

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Spacecraft.h"
#include "Mothership.h"

class Game
{
    Spacecraft player;      //Dichiaro un oggetto di tipo navicella per il giocatore
	Cannon c;               //Dichiaro un oggetto cannon per gestire i colpi
	Mothership aliens;      //Dichiaro un oggetto mothership per gestire i nemici
	int score;              //Per il punteggio
	int highScore;          //Miglior punteggio

    public:

    Game();                 //Costruttore
    void StartMessage();    //Messaggio iniziale
    void UpdateScreen();    //Stampa a video lo stato attuale della partita
    bool MoveSpacesraft();  //Gestisce l'input per lo spastamento della navicella del giocatore
    void SpacecraftShoot(); //Sparo della navicella del giocatore
    void GenerationEnemy(); //Genera i nemici
    void MoveEnemy();       //Muove i nemici
    void Hitted();          //Controlla se il nemico è stato colpito
    void Collision();       //Controlla se la navicella alleata è stata colpita
    void UpdateScore();     //Aggiorna il punteggio attuale della partita
    void SaveScore();       //Salva il miglior punteggio
    void ReadHighScore();   //Imposta la variabile highScore
};

#endif // GAME_H_INCLUDED
