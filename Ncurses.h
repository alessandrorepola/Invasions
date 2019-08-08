/**************************************************************
* File Ncurses.h                                              *
* Imposta tutte le funzionalità della libreria ncurses/curses *
**************************************************************/

#ifndef NCURSES_H_INCLUDED
#define NCURSES_H_INCLUDED

// Per Windows uso la direttiva curses.h
// per indicare la libreria pdcurses
// per Linux uso la direttiva ncurses.h
// per referenziare la libreria ncurses nativa di Linux

#if defined (__WIN32__) && !defined (__CYGWIN__)
    #include <curses.h>
#else
    #include <ncurses.h>
#endif

//Dimensioni della finestra principale
#define WIN_WIDTH 120
#define WIN_HEIGHT 35

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

namespace Ncurses
{
    //Inizializza la modalità ncurses/curses
    void Init();

    //Termina la modalità ncurses/curses
    void Exit();

    //Dichiaro un ulteriore namespace per la gestione dei colori per le finestre ncurses
    namespace Colors
    {
        //Inizializza i colori per stdscr di ncurses
        void Init();

        //Inizializza le coppie di colori (foreground e background)
        void ColorPair();
    }
}

#endif // NCURSES_H_INCLUDED
