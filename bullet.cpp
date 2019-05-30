//File bullet.cpp
#include "Bullet.h"

//Costruttore che posiziona il colpo
Bullet::Bullet(int r, int c, int type)
{
    next = NULL;
    prev = NULL;

    //Inizializzo le coordinate del colpo
    row = r;
    column = c;
    id = type;

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
        if (id == PLAYER)
        {
            --row;
        }
        else
        {
            ++row;
        }
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

//Restituisce l'id del colpo
int Bullet::GetId()
{
    return id;
}

//Distruttore
Bullet::~Bullet()
{
    next = NULL;
    prev = NULL;
}
