/********************************************************************************************************
* File Game.h                                                                                           *
* Contiene la classe Game che gestisce gli oggetti del gioco come la navicella, i nemici, i colpi, ecc. *
********************************************************************************************************/

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Spacecraft.h"
#include "Mothership.h"
#include "File.h"
#include "Graphics/Window.h"

class Game
{
    Window main_win;        //Apro una finestra principale
    Window *game_win;       //Dichiaro un puntatore alla finestra di gioco
    Window *start_message;  //Messaggio iniziale
    Window *score_win;      //Puntatore alla finestra per il punteggio
    Window *life_win;       //Puntatore alla finestra con la vita del giocatore
    Spacecraft player;      //Dichiaro un oggetto di tipo navicella per il giocatore
	Cannon c;               //Dichiaro un oggetto cannon per gestire i colpi
	Mothership aliens;      //Dichiaro un oggetto mothership per gestire i nemici
	File f;                 //Oggetto per la gestione dei file
	int score;              //Per il punteggio
	int bestScore;          //Miglior punteggio

	void Banner();          //Banner iniziale
    void StartMessage();    //Messaggio iniziale
    void Help(Window &);    //Guida
    void UserChoice(int);   //Scelta dell'utente relativa al menu principale
    void UpdateScreen();    //Stampa a video lo stato attuale della partita
    int UserInput();        //Gestisce l'input per lo spastamento della navicella del giocatore
    void EnemyHitted();     //Controlla se il nemico è stato colpito
    void PlayerHitted();    //Controlla se il giocatore è stato colpito
    void Collision();       //Controlla se la navicella alleata è stata colpita
    void UpdateScore(int);  //Aggiorna il punteggio attuale della partita
    void SaveBestScore();       //Salva il miglior punteggio
    void SetBestScore();   //Imposta la variabile highScore
    void SaveGameStatus();        //Per salvare la partita attuale
    void ResumeLastMatch();     //Per riprendere dalla partita precedente
    void PrintScore();      //Inizializza il punteggio
    void PrintLife();       //Inizializza la vita del giocatore

    public:

    Game();                 //Costruttore
    ~Game();                //Distruttore
    bool StartGameLoop();    //Loop della partita
    void MainScreen();      //Schermata principale
    Window &GetMainWin();   //Restiruisce un riferimento alla finestra principale
};

#endif // GAME_H_INCLUDED
