//File Invasions.h per la dichiarazione delle costanti e delle librerie necessarie
#ifndef INVASIONS_H_INCLUDED
#define INVASIONS_H_INCLUDED

#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <unistd.h> //per la funzione usleep
#include "Ncurses.h"

//Numero di scelte del menu
#define N_CHOICES 4

//Velocità di movimento del colpo
#define BULLET_SPEED 0.1

//Danno inflitto dal colpo
#define BULLET_DAMAGE 1

//Tempo di generazione dei colpi
#define TIME_PLAYER_BULLET 0.3
#define TIME_ENEMY_BULLET 5
//Constante per inizializzare le variabili a zero
#define INIT 0

//Coordinate Iniziali della console di gioco
#define START_XY 1

//Definisco la vita del nemico e della navicella dell'utente
#define SPACECRAFT_LIFE 10
#define ENEMY_LIFE 3

//Definesco le entità del giocatore e del nemico per la gestione dei colpi
#define ENEMY 100
#define PLAYER 101

//Velocità di movimento dei nemici
#define ENEMY_SPEED 0.3

//Tempo di generazione dei nemici
#define ENEMY_GENERATION_TIME 3.5

//Indica i 4 lati della console
#define CONSOLE_SIDE 4

#define FIRST_MENU 10
#define SECONDARY_MENU 11

#define WIN_MESS_WIDTH 22
#define WIN_MESS_HEIGHT 12

//Definisce quali sono i quattro lati della console
enum ConsoleSide
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

//Imposto le direzioni in cui si può muovere il nemico
enum Directions
{
    NORTH,
    SOUTH,
    EST,
    WEST,
    NORTH_EST,
    NORTH_WEST,
    SOUTH_EST,
    SOUTH_WEST,
};

//Enumero le scelte dell'utente
enum MainMenuChoice
{
    NEW_MATCH = 1,
    LAST_MATCH,
    HELP,
    EXIT,
};

//Enumero le scelte dell'utente sul menu secondario
enum SecondaryMenuChoice
{
    RESUME = 1,
    RESTART,
    MAIN_MENU,
};

namespace Globals
{
    void Init();       //Inizializza la schermata di ncurses
    void SizeTerm();   //Imposta le dimensioni del terminale
    void End();        //Termina il programma
}

#endif // GLOBALS_H_INCLUDED
