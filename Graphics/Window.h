/****************************************
* File Window.h                         *
* Per gestire le finestre nella console *
****************************************/
#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include "../Invasions.h"

class Window
{
    //Dichiaro le variabili per le coordinate in cui cominciano le finestre
    int startx;
    int starty;

    //Dichiaro le variabili per le dimensioni delle finestre
    int sizex;
    int sizey;

    //Dichiaro un puntatore alla struttura WINDOW
    WINDOW *win;

    public:

    Window();               //Costruttore di default
    Window(WINDOW*);        //Costruttore per le sottofinestre
    ~Window();              //Distruttore
    void PrintWinBorder();  //Aggiorna e Stampa a video i bordi della console
    WINDOW *GetWin();       //Restituisce un puntatore alla finestra principale

};

#endif // WINDOW_H_INCLUDED
