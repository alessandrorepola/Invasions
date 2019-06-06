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
    int width;
    int height;

    //Dichiaro un puntatore alla struttura WINDOW
    WINDOW *win;

    public:

    Window();               //Costruttore di default
    Window(WINDOW*);        //Costruttore per le sottofinestre
    Window(WINDOW*, int, int, int, int);        //Costruttore per le sottofinestre
    ~Window();              //Distruttore
    void PrintWinBorder();  //Aggiorna e Stampa a video i bordi della console
    void SetWindow();       //Imposta le dimensioni se necessario
    WINDOW *GetWin();       //Restituisce un puntatore alla finestra principale
    int GetHeight();        //Restituisce l'altezza della finestra
    int GetWidth();         //Restituisce la larghezza della finestra
    int GetX();             //Restituisce la coordinata x della finestra
    int GetY();             //Restituisce la coordinata y della finestra

};

#endif // WINDOW_H_INCLUDED
