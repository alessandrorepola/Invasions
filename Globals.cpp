/*******************************************************
* Globals.cpp                                          *
* Implementazione delle funzioni del namespace Glogals *
*******************************************************/

#include "Globals.h"
#include <iostream>

//Inizializza la modalità curses
void Globals::Init()
{
    SizeTerm();
    Ncurses::Init();
    Ncurses::Colors::Init();
    Ncurses::Colors::ColorPair();
	srand(time(NULL));      //Per la generazione di valori random
}

//Ridimensiona il terminale
void Globals::SizeTerm()
{
    std::cout <<"\e[8;"<< WIN_HEIGHT << ";" << WIN_WIDTH << "t";
}

//Termina il programma
void Globals::End()
{
    Ncurses::Exit();
    exit(0);
}
