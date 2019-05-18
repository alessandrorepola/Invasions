//File Invasions.h per la dichiarazione delle costanti e delle librerie necessarie
#ifndef INVASIONS_H_INCLUDED
#define INVASIONS_H_INCLUDED

#include <ctime>
#include <stdio.h>
#include <windows.h>
#include <cstdlib>
//#ifdef WIN32
    #include <curses.h>
/*#else
    #include <ncurses.h>
#endif*/

//Velocità di movimento del colpo
#define BULLET_SPEED 0.1

//Danno inflitto dal colpo
#define BULLET_DAMAGE 1

//Tempo di generazione dei colpi
#define BULLET_GENERATION_TIME 0.3

//Constante per inizializzare le variabili a zero
#define INIT 0

//Dimensioni della console
#define CONSOLE_LENGTH 100
#define CONSOLE_HIGH 30

//Definisco la vita del nemico e della navicella dell'utente
#define SPACECRAFT_LIFE 10
#define ENEMY_LIFE 2

//Velocità di movimento dei nemici
#define ENEMY_SPEED 0.4

//Indica i 4 lati della console
#define CONSOLE_SIDE 4

#define ENEMY_GENERATION_TIME rand()%146732 == 0

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


#endif // INVASIONS_H_INCLUDED
