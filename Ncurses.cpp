/*****************************************
* File Ncurses.cpp                       *
* Implementa i metodi del file Ncurses.h *
*****************************************/

#include "Ncurses.h"

//Inizializzo la modatita' ncurses/curses
void Ncurses::Init()
{
    initscr();                          //Inizializzo la modalita' curses
    curs_set (false);		            //Rende il cursore invisibile
	keypad (stdscr, true);	            //Abilita i tasti freccia
	noecho ();				            //Disabilita l'echo dei tasti premuti
	nodelay (stdscr, true);	            //Se non viene digitato alcun tasto la funzione getch() restituisce ERR
	resize_term(WIN_HEIGHT, WIN_WIDTH); //Ridimensiona il terminale
}

//Termina la modalità ncurses/curses
void Ncurses::Exit()
{
    erase();
    refresh();
    endwin();
}

//Inizializza i colori
void Ncurses::Colors::Init()
{
    //Funzione della libreria ncurses per inizializzare i colori
    start_color();

    //Modifico le tonalità dei colori per renderli più brillanti
    init_color (COLOR_RED,     FULL_COLOR,  EMPTY_COLOR,  EMPTY_COLOR);
    init_color (COLOR_BLUE,    EMPTY_COLOR, EMPTY_COLOR,  FULL_COLOR);
    init_color (COLOR_YELLOW,  FULL_COLOR,  FULL_COLOR,   EMPTY_COLOR);
    init_color (COLOR_GREEN,   EMPTY_COLOR, FULL_COLOR,   EMPTY_COLOR);
    init_color (ORANGE,        FULL_COLOR,  MEDIUM_COLOR, EMPTY_COLOR);
    init_color (COLOR_CYAN,    EMPTY_COLOR, FULL_COLOR,   FULL_COLOR);
    init_color (COLOR_MAGENTA, FULL_COLOR,  EMPTY_COLOR,  EMPTY_COLOR);
    init_color (COLOR_WHITE,   FULL_COLOR,  FULL_COLOR,   FULL_COLOR);
}

//Crea gli abbinamenti (foreground e background)
void Ncurses::Colors::ColorPair()
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
