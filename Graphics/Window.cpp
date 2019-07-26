/****************************************************
* File Window.cpp                                   *
* Per gestire le finestre all'interno della console *
****************************************************/

#include "Window.h"
#include <iostream>

Window::Window()
{
    //Inizializzo le coordinate
    startx = INIT;
    starty = INIT;
    getmaxyx(stdscr, height, width);

    if (height < WIN_HEIGHT || width < WIN_WIDTH)
    {
        refresh();
        endwin();
        std::cerr << "Errore! La tua console e' piu' piccola di "
                  << WIN_WIDTH << " x " << WIN_HEIGHT << std::endl
                  << "Se non e' stata ridimensionata automaticamente dal programma prova a farlo manualmente";

        exit(1);
    }

    //Creo una finestra principale
    win = newwin(height, width, starty, startx);
}

Window::Window(WINDOW *parent, int sx, int sy, int ex, int ey )
{
    //modifico i valori delle variabili passate
    //come argomento per escludere i bordi
    startx = ++sx;
    starty = ++sy;
    width = ex-2;
    height = ey-2;

    //Creo una finestra principale
    win = derwin(parent, height, width, starty, startx);
}

void Window::PrintWinBorder()
{
    //Se è la finestra di gioco
    if (startx == START_XY)
    {
        werase(win);

        //Creo dei bordi più belli
        wborder(win,
                ACS_BLOCK,
                ACS_BLOCK,
                ACS_BLOCK,
                ACS_BLOCK,
                ACS_BLOCK,
                ACS_BLOCK,
                ACS_BLOCK,
                ACS_BLOCK);
    }
    else
    {
        box(win, ACS_VLINE, ACS_HLINE);
    }
}

//Restituisce il puntatore alla finestra
WINDOW *Window::GetWin()
{
    return win;
}

//Restitusce l'altezza della finestra
int Window::GetHeight()
{
    return height;
}

//Restitusce la larghezza della finestra
int Window::GetWidth()
{
    return width;
}

//Restitusce la coordinata x della finestra
int Window::GetX()
{
    return startx;
}

//Rsestitusce la coordinata y della finestra
int Window::GetY()
{
    return starty;
}

Window::~Window()
{
    delwin(win);
}
