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

//Sposta il colpo
void Bullet::Move()
{
    clock_t time;
    double diff = 0;

    //Controllo se ci sono altri colpi
    if (next != NULL)
        next->Move();

    //Controllo il tempo trascorso dall'ultimo colpo
    time = clock();
    diff = (double)(time-start);
    diff = diff/CLOCKS_PER_SEC;

    //Controllo se si può muovere
    if (diff >= 0.05)
    {
        start = time;
        row--;
    }
}

//Distruttore
Bullet::~Bullet()
{
    //TO DO
}
