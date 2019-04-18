//File cannon.h
#ifndef CANNON_H_INCLUDED
#define CANNON_H_INCLUDED

#include "bullet.h"

class Cannon
{
    Bullet *first; //Puntatore al primo colpo sparato
    Bullet *last;  //Puntatore all'utimo colpo sparato
    clock_t start; //Per cronometrare il tempo

    public:

    Cannon();                 //Costruttore
    void AddBullet(int, int); //Genera un nuovo colpo con le sue coordinate
    void RemoveBullet();      //Remuove un colpo
    void MoveBullet();        //Muove i colpi
    void Draw();              //Disegna i colpi
    ~Cannon();                //Distruttore
};

#endif // CANNON_H_INCLUDED
