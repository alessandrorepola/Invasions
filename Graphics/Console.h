/**********************************************
* File Console.h                              *
* Per gestire l'aspetto grafico della console *
**********************************************/
#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED

#include "../Invasions.h"

class Console
{
    //Dichiaro le coordinate per i menu
    int startx;
    int starty;

    //Dichiaro un puntatore alla struttura WINDOW
    WINDOW *console_win;

    public:

    //Costruttore e distruttore
    Console();
    ~Console();

    //Dichiaro un metodo per la stampa del menu
    void PrintConsole();
};

#endif // CONSOLE_H_INCLUDED
