/****************************************************
* File Window.cpp                                   *
* Per gestire le finestre all'interno della console *
****************************************************/

#include "Window.h"

Window::Window()
{
    //Inizializzo le coordinate
    startx = INIT;
    starty = INIT;
    endx = WIN_LENGTH;
    endy = WIN_HIGH;

    //Creo una finestra principale
    win = newwin(endy, endx, starty, startx);
}

Window::Window(int sx, int sy, int ex, int ey)
{
    //Inizializzo le coordinate
    startx = sx;
    starty = sy;
    endx = ex;
    endy = ey;

    //Creo una finestra principale
    win = newwin(endy, endx, starty, startx);
}

void Window::PrintWinBorder()
{
    wclear(win);

    //Se è la finestra di gioco
    if (startx == 1)
    {
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

WINDOW *Window::GetWin()
{
    return win;
}

Window::~Window()
{
    delwin(win);
}
