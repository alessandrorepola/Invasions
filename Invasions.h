//File Invasions.h per la dichiarazione delle costanti e delle librerie necessarie
#ifndef INVASIONS_H_INCLUDED
#define INVASIONS_H_INCLUDED

#include <ctime>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>

#ifndef WIN32
    #include <curses.h>
#else
    #include <ncurses.h>
#endif

//Numero di scelte del menu
#define N_CHOICES 5

//Velocità di movimento del colpo
#define BULLET_SPEED 0.1

//Danno inflitto dal colpo
#define BULLET_DAMAGE 1

//Tempo di generazione dei colpi
#define BULLET_GENERATION_TIME 0.3

//Constante per inizializzare le variabili a zero
#define INIT 0

//Dimensioni della console
#define CONSOLE_LENGTH 77
#define CONSOLE_HIGH 24

//Dimensione del menu
#define MENU_LENGHT 25
#define MENU_HIGH 10

//Definisco la vita del nemico e della navicella dell'utente
#define SPACECRAFT_LIFE 1
#define ENEMY_LIFE 3

//Velocità di movimento dei nemici
#define ENEMY_SPEED 0.2

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

//Enumero le scelte dell'utente
enum Choice
{
    NEW_MATCH = 1,
    LAST_MATCH,
    GUIDE,
    CHANGE_NAME,
    EXIT,
};

#endif // INVASIONS_H_INCLUDED
