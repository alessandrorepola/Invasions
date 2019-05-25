/****************************************
* File Window.h                         *
* Per gestire le finestre nella console *
****************************************/
#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include "../Invasions.h"

class Window
{
    //Dichiaro le coordinate per i menu
    int startx;
    int starty;

    //Dichiaro un puntatore alla struttura WINDOW
    WINDOW *console_win;

    public:

    Window();        //Costruttore
    ~Window();       //Distruttore
    void PrintConsole();  //Finestra della console
    WINDOW *GetConsole(); //Restituisce un puntatore alla finestra principale

};

#endif // CONSOLE_H_INCLUDED
