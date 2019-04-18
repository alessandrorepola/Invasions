//File Infasione.h per la dichiarazione delle costanti e delle librerie necessarie
#ifndef INVASIONS_H_INCLUDED
#define INVASIONS_H_INCLUDED

#include <ctime>
#ifdef WIN32
    #include <curses.h>
#else
    #include <ncurses.h>
#endif

#define BULLET_SPEED 0.1
#define BULLET_DAMAGE 1
#define BULLET_GENERATION_TIME 0.3
#define INIT 0
#define CONSOLE_LENGTH 100
#define CONSOLE_HIGH 30
#define SPACECRAFT_LIFE 10

#endif // INVASIONS_H_INCLUDED
