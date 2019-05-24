/**********************************************
* File Console.cpp                            *
* Per gestire l'aspetto grafico della console *
**********************************************/

#include "Console.h"

Console::Console()
{
    //Inizializzo le coordinate iniziali del menu
    startx = INIT;
    starty = INIT;

    console_win = newwin(CONSOLE_HIGH, CONSOLE_LENGTH, starty, startx);
}

void Console::PrintConsole()
{
	box(console_win, INIT, INIT);
	wrefresh(console_win);
}

Console::~Console()
{
    delwin(console_win);
}
