//File bullet.h
#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include "spacecraft.h"
#define DELAY 1
#define DAMAGE 1

class Bullet
{
    friend class Spacecraft;

    int speed;        //Velocit� del colpo
    int damage;       //Danno del colpo
    int row;          //Riga del colpo
    int column;       //Colonna del colpo
    Bullet *next;     //Puntatore al colpo successivo
    Bullet *prev;     //Puntatore al colpo precedente
    void PrintBlow(); //Stampa il colpo

    public:

    Bullet();           //Costruttore
    int Move();       //Muove il colpo sparato
    ~Bullet();          //Distruttore
};

#endif // BULLET_H_INCLUDED
