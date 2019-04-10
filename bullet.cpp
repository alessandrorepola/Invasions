//File bullet.cpp
#include "bullet.h"

//costruttore
Bullet::Bullet()
{
    speed = DELAY;
    damage = DAMAGE;
    next = NULL;
    prev = NULL;
}

//Disegna il colpo nella sua posizione attuale
void Bullet::PrintBlow()
{
    mvaddch(row,column,'.');
    refresh();
    delay_output(100);
}

//distruttore
Bullet::~Bullet()
{
    //TO DO
}
