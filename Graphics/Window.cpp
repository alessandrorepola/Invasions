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
    width = WIN_WIDTH;
    height = WIN_HEIGHT;

    //Creo una finestra principale
    win = newwin(height, width, starty, startx);
}

Window::Window(WINDOW *parent)
{
    //Inizializzo le coordinate
    startx = START_XY;
    starty = START_XY;
    width = GAME_WIN_WIDTH+START_XY;
    height = GAME_WIN_HEIGHT+START_XY;

    //Creo una finestra principale
    win = derwin(parent, height, width, starty, startx);
}

Window::Window(WINDOW * parent, int sx, int sy, int ex, int ey )
{
    startx = sx;
    starty = sy;
    width = ex;
    height = ey;

    //Creo una finestra principale
    win = derwin(parent, height, width, starty, startx);
}

void Window::PrintWinBorder()
{
    //Se è la finestra di gioco
    if (width == GAME_WIN_WIDTH+START_XY)
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
