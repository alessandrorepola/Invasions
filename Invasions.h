//File Invasions.h per la dichiarazione delle costanti e delle librerie necessarie
#ifndef INVASIONS_H_INCLUDED
#define INVASIONS_H_INCLUDED

#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <unistd.h> //per la funzione usleep

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
#define TIME_PLAYER_BULLET 0.3
#define TIME_ENEMY_BULLET 4

//Constante per inizializzare le variabili a zero
#define INIT 0

//Coordinate Iniziali della console di gioco
#define START_XY 1

//Dimensioni della finestra principale
#define WIN_LENGTH 103
#define WIN_HIGH 37

//Dimensioni della finestra di gioco
#define GAME_WIN_LENGTH 100
#define GAME_WIN_HIGH 30

//Dimensione del menu
#define MENU_LENGHT 25
#define MENU_HIGH 10

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

//Dichiaro le costanti per i colori
enum Colors
{
    RED = 10,
    YELLOW,
    BLUE,
    ORANGE,
    CYAN,
    GREEN,
    MAGENTA,
    WHITE,

    //Per regolare l'intensità di colore
    EMPTY_COLOR = 0,
    MEDIUM_COLOR = 500,
    FULL_COLOR = 1000,
};

#endif // INVASIONS_H_INCLUDED
