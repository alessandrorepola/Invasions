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

//Costruttore che posiziona il colpo
Bullet::Bullet(int r, int c)
{
    speed = DELAY;
    damage = DAMAGE;
    next = NULL;
    prev = NULL;

    //Inizializzo le coordinate del colpo
    row = r;
    column = c;

    //Inizializzo il tempo
    start = clock();
}

//Distruttore
Bullet::~Bullet()
{
    //TO DO
}
