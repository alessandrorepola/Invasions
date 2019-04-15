#ifndef CANNON_H_INCLUDED
#define CANNON_H_INCLUDED

#include "bullet.h"

class Cannon
{
    Bullet *first; //Puntatore al primo colpo sparato
    Bullet *last;  //Puntatore all'utimo colpo sparato
    Bullet *iter;  //Puntatore mobile

    public:

    Cannon();                 //Distruttore
    void AddBullet(int, int); //Genera un nuovo colpo con le sue coordinate
    void RemoveBullet();      //Remuove un colpo
    ~Cannon();                //Distruttore
};

#endif // CANNON_H_INCLUDED
