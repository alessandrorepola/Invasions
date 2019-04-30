//File bullet.cpp
#include "bullet.h"

//costruttore
Bullet::Bullet()
{
    next = NULL;
    prev = NULL;
}

//Costruttore che posiziona il colpo
Bullet::Bullet(int r, int c)
{
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
    double diff = INIT;

    //Controllo se ci sono altri colpi
    if (next != NULL)
        next->Move();

    //Controllo il tempo trascorso dall'ultimo colpo
    time = clock();
    diff = (double)(time-start);
    diff = diff/CLOCKS_PER_SEC;

    //Controllo se si può muovere
    if (diff >= BULLET_SPEED)
    {
        start = time;
        row--;
    }
}

//Restituisce la riga del colpo
int Bullet::GetRow()
{
    return row;
}

//Restituisce la colonna del colpo
int Bullet::GetColumn()
{
    return column;
}

//Distruttore
Bullet::~Bullet()
{
    next = NULL;
    prev = NULL;
}
