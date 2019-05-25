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

    //Creo una finestra principale
    console_win = newwin(CONSOLE_HIGH+START_XY, CONSOLE_LENGTH+START_XY, starty, startx);
}

void Window::PrintConsole()
{
    wclear(console_win);
    box(console_win, ACS_VLINE, ACS_HLINE);
}

WINDOW *Window::GetConsole()
{
    return console_win;
}

Window::~Window()
{
    delwin(console_win);
}
