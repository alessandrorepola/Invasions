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

    Cannon();                   //Costruttore
    void AddObject(int, int);   //Genera un nuovo colpo con le sue coordinate
    void RemoveFirst();         //Remuove il primo colpo della lista
    void RemoveLast();          //Remuove l'ultimo colpo della lista
    void RemoveObject(Bullet*); //Rimuove il colpo specificato
    void MoveObject();          //Muove i colpi
    void Draw();                //Disegna i colpi
    ~Cannon();                  //Distruttore
};

#endif // CANNON_H_INCLUDED
