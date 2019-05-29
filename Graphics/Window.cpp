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
    startx = START_COORD;
    starty = START_COORD;
    sizex = GAME_WIN_LENGTH+START_COORD;
    sizey = GAME_WIN_HIGH+START_COORD;

    //Creo una finestra principale
    win = derwin(parent, sizey, sizex, starty, startx);
}

void Window::PrintWinBorder()
{
    werase(win);

    //Se è la finestra di gioco
    if (startx == START_COORD)
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
    wrefresh(win);
}

WINDOW *Window::GetWin()
{
    return win;
}

Window::~Window()
{
    delwin(win);
}
