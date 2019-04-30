//File bullet.h
#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include "Invasions.h"

class Bullet
{
    friend class Cannon;

    int row;          //Riga del colpo
    int column;       //Colonna del colpo
    Bullet *next;     //Puntatore al colpo successivo
    Bullet *prev;     //Puntatore al colpo precedente
    clock_t start;    //Misura il tempo da quando è stato sparato il colpo
    Bullet(int, int); //Costruttore che prende come argomento la riga e la colonna
    void Move();      //Muove il colpo sparato

    public:

    Bullet();         //Costruttore di default
    int GetRow();     //Restituisce la riga del colpo
    int GetColumn();  //Restituisce la colonna del colpo
    ~Bullet();        //Distruttore
};

#endif // BULLET_H_INCLUDED
