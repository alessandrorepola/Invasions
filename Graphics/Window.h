/****************************************
* File Window.h                         *
* Per gestire le finestre nella console *
****************************************/
#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include "../Invasions.h"

class Window
{
    //Dichiaro le coordinate per le finestre
    int startx;
    int starty;
    int endx;
    int endy;

    //Dichiaro un puntatore alla struttura WINDOW
    WINDOW *win;

    public:

    Window();
    Window(int, int, int, int);      //Costruttore
    ~Window();              //Distruttore
    void PrintWinBorder();  //Aggiorna Stampa a video i bordi della console
    WINDOW *GetWin();       //Restituisce un puntatore alla finestra principale

};

#endif // WINDOW_H_INCLUDED
