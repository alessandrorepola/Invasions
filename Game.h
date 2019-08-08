/********************************************************************************************************
* File Game.h                                                                                           *
* Contiene la classe Game che gestisce gli oggetti del gioco come la navicella, i nemici, i colpi, ecc. *
********************************************************************************************************/

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Spacecraft.h"
#include "File.h"
//#include "Widgets.h"
#include "Graphics/Window.h"
#include "List.h"

class Game
{
    Window main_win;        //Apro una finestra principale
    Window *game_win;       //Dichiaro un puntatore alla finestra di gioco
    Window *info_win;       //Puntatore alla finestra per le informazioni sulla partita
    Spacecraft *player;     //Dichiaro un oggetto di tipo navicella per il giocatore
	List PlayerBulletList;  //Dichiaro una lista per gestire i colpi sparati dal giocatore
	List EnemyBulletList;   //Dichiaro una lista per gestire i colpi sparati dal giocatore
	List EnemyList;         //Dichiaro una lista per gestire i nemici
	File f;                 //Oggetto per la gestione dei file
	int score;              //Per il punteggio
	int bestScore;          //Miglior punteggio

    void UserChoice(int);   //Scelta dell'utente relativa al menu principale
    void UpdateScreen();    //Stampa a video lo stato attuale della partita
    int UserInput();        //Gestisce l'input per lo spastamento della navicella del giocatore
    void EnemyRoutine();    //Routine dei nemici che comprende sparo e spostamento
    void EnemyHitted();     //Controlla se il nemico � stato colpito
    void PlayerHitted();    //Controlla se il giocatore � stato colpito
    void Collision();       //Controlla se la navicella alleata � stata colpita
    void UpdateScore(int);  //Aggiorna il punteggio attuale della partita
    void SaveBestScore();   //Salva il miglior punteggio
    void SetBestScore();    //Imposta la variabile highScore
    void SaveGameStatus();  //Per salvare la partita attuale
    void ResumeLastMatch(); //Per riprendere dalla partita precedente
    void PrintInfo();       //Stampa il conentenuto della finestra info_win

    public:

    Game();                 //Costruttore
    ~Game();                //Distruttore
    bool StartGameLoop();    //Loop della partita
    void MainScreen();      //Schermata principale
    Window &GetMainWin();   //Restiruisce un riferimento alla finestra principale
};

#endif // GAME_H_INCLUDED
