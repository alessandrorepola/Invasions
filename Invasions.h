//File Invasions.h per la dichiarazione delle costanti e delle librerie necessarie
#ifndef INVASIONS_H_INCLUDED
#define INVASIONS_H_INCLUDED

#include <ctime>
#include <cstdio>
#include <cstdlib>

#ifndef WIN32
    #include <curses.h>
#else
    #include <ncurses.h>
#endif

//Numero di scelte del menu
#define N_CHOICES 4

//Velocità di movimento del colpo
#define BULLET_SPEED 0.1

//Danno inflitto dal colpo
#define BULLET_DAMAGE 1

//Tempo di generazione dei colpi
#define BULLET_GENERATION_TIME 0.3

//Constante per inizializzare le variabili a zero
#define INIT 0

//Coordinate Iniziali della console di gioco
#define START_XY 1

//Dimensioni della console
#define CONSOLE_LENGTH 100
#define CONSOLE_HIGH 30

//Dimensione del menu
#define MENU_LENGHT 25
#define MENU_HIGH 10

//Definisco la vita del nemico e della navicella dell'utente
#define SPACECRAFT_LIFE 1
#define ENEMY_LIFE 3

//Velocità di movimento dei nemici
#define ENEMY_SPEED 0.3

//Indica i 4 lati della console
#define CONSOLE_SIDE 4

#define FIRST_MENU 10
#define SECONDARY_MENU 11

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
