//File spacecraft.cpp
#include "spacecraft.h"

//Costruttore
spacecraft::spacecraft()
{
    life = LIFE;
    row = 15;
    column = 50;
}

//Movimeto della navicella
int spacecraft::Move(int key)
{
    switch (key)
    {
        //tasti direzionali
        case KEY_UP:
        --row;
        break;

        case KEY_DOWN:
        ++row;
        break;

        case KEY_LEFT:
        --column;
        break;

        case KEY_RIGHT:
        ++column;
        break;

        case ' ':
            return SHOT;

        case 'q':
        case 'Q':
            return EXIT;

        // Se non viene premuto nessun tasto o un altro tasto diverso dai precedenti esce
        case ERR:
        default:
            break;

    }
    clear();
    mvprintw(row,column-2,"\\-||-/");
    return MOVE;
}

//Distruttore
spacecraft::~spacecraft()
{
    return;
}
