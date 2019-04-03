//File blow.cpp
#include "blow.h"

//costruttore
blow::blow()
{
    speed = DELAY;
    damage = DAMAGE;
}

//Movimento del colpo
void blow::Move(int row, int column)
{
    mvprintw(row,column,".");
    refresh();
}

//distruttore
blow::~blow()
{
    return;
}
