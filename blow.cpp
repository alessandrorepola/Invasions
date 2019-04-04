//File blow.cpp
#include "blow.h"
#include "spacecraft.h"

//costruttore
blow::blow()
{
    speed = DELAY;
    damage = DAMAGE;
}

//Movimento del colpo
void blow::Move(spacecraft allied)
{
    int i=allied.row-1;
    while (i>=-1)
    {
        clear();
        mvprintw(allied.row,allied.column-2,"\\-||-/");
        mvaddch(i,allied.column,'.');
        refresh();
        i--;
        for (long j=0; j<10000000; j++);

    }
}

//distruttore
blow::~blow()
{
    return;
}
