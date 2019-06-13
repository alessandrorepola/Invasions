
#include "Invasions.h"
#include "Game.h"
#include "Graphics/Menu.h"

//Imposta le varie funzioni per ncurses
void SetConsole();

//Imposta le dimensioni del terminale
void SizeTerm();

//Inizializza le tonalità di colore
void InitColor();

//Inizializzo le coppie di colori
void ColorPair();

int main()
{
    initscr();     //Inizializzo la modalita' curses
    start_color(); //Per utilizzare i colori
    InitColor();   //Inizializzo le tonalità di colore
    ColorPair();   //Inizializzo le coppie di colori
    SetConsole();  //Imposto le funzioni per curses
    bool endGame = true;  //Per uscire dal gioco
    do
    {
        //Oggetto game
        Game game;

        //Se l'utente ricomincia direttamente una nuova partita
        //Salta la fase della schermata principale
        if (endGame)
        {
            //Schermata principale
            game.MainScreen();
        }

        //loop "infinito" della partita
        endGame = game.StartGameLoop();
    }
    while (!endGame);  //Finchè l'utente non decide di uscire dal gioco
    endwin(); //Termina la modalita' curses
    return 0;
}

void SetConsole()
{
    SizeTerm();             //Imposta le dimensioni della console
    curs_set (false);		//Rende il cursore invisibile
	keypad (stdscr, true);	//Abilita i tasti freccia
	noecho ();				//Disabilita l'echo dei tasti premuti
	srand(time(NULL));      //Per la generazione di valori random
	nodelay (stdscr, true);	//Se non viene digitato alcun tasto la funzione getch() restituisce ERR
}

//Ridimensiona il terminale
void SizeTerm()
{
    resize_term(WIN_HEIGHT+START_XY, WIN_WIDTH+START_XY);
}

//Inizializzo le coppie di colori
void InitColor()
{
    init_color (COLOR_RED,     FULL_COLOR,  EMPTY_COLOR,  EMPTY_COLOR);
    init_color (COLOR_BLUE,    EMPTY_COLOR, EMPTY_COLOR,  FULL_COLOR);
    init_color (COLOR_YELLOW,  FULL_COLOR,  FULL_COLOR,   EMPTY_COLOR);
    init_color (COLOR_GREEN,   EMPTY_COLOR, FULL_COLOR,   EMPTY_COLOR);
    init_color (ORANGE,        FULL_COLOR,  MEDIUM_COLOR, EMPTY_COLOR);
    init_color (COLOR_CYAN,    EMPTY_COLOR, FULL_COLOR,   FULL_COLOR);
    init_color (COLOR_MAGENTA, FULL_COLOR,  EMPTY_COLOR,  EMPTY_COLOR);
    init_color (COLOR_WHITE,   FULL_COLOR,  FULL_COLOR,   FULL_COLOR);
}

//Inizializzo le coppie di colori
void ColorPair()
{
    //Controllo che il terminale supporti i colori
    if (has_colors())
    {
        //Controllo che il terminale consenta di cambiare i colori di default
        if (can_change_color())
        {
            //Inizializzo i colori
            init_pair(RED,      COLOR_RED,     COLOR_BLACK);
            init_pair(YELLOW,   COLOR_YELLOW,  COLOR_BLACK);
            init_pair(BLUE,     COLOR_BLUE,    COLOR_BLACK);
            init_pair(ORANGE,   ORANGE,        COLOR_BLACK);
            init_pair(CYAN,     COLOR_CYAN,    COLOR_BLACK);
            init_pair(GREEN,    COLOR_GREEN,   COLOR_BLACK);
            init_pair(MAGENTA,  COLOR_MAGENTA, COLOR_BLACK);
            init_pair(WHITE,    COLOR_WHITE,   COLOR_BLACK);
        }
    }
}
