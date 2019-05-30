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
    sizex = WIN_LENGTH;
    sizey = WIN_HIGH;

    //Creo una finestra principale
    win = newwin(sizey, sizex, starty, startx);
}

Window::Window(WINDOW *parent)
{
    //Inizializzo le coordinate
    startx = START_XY;
    starty = START_XY;
    sizex = GAME_WIN_LENGTH+START_XY;
    sizey = GAME_WIN_HIGH+START_XY;

    //Creo una finestra principale
    win = derwin(parent, sizey, sizex, starty, startx);
}

Window::Window(WINDOW * parent, int sx, int sy, int ex, int ey )
{
    startx = sx;
    starty = sy;
    sizex = ex;
    sizey = ey;

    //Creo una finestra principale
    win = derwin(parent, sizey, sizex, starty, startx);
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
        wrefresh(win);
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
