//File bullet.h
#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include "Globals.h"

class Bullet
{
    friend class Cannon;

    int row;          //Riga del colpo
    int column;       //Colonna del colpo
    Bullet *next;     //Puntatore al colpo successivo
    Bullet *prev;     //Puntatore al colpo precedente
    clock_t start;    //Misura il tempo da quando è stato sparato il colpo
    Bullet(int, int, int); //Costruttore che prende come argomento la riga e la colonna
    void Move();      //Muove il colpo sparato
    int id;           //Identifica l'appartenenza del colpo

    public:

    Bullet();         //Costruttore di default
    Bullet(Bullet&);   //Costruttore che ricrea un colpo con le caratteristiche di quello salvato su file
    int GetRow();     //Restituisce la riga del colpo
    int GetColumn();  //Restituisce la colonna del colpo
    int GetId();      //Restituisce l'id del colpo
    Bullet *GetPrev();//Restituisce il puntatore al colpo precedente
    Bullet *GetNext();//Restituisce il puntatore al colpo successivo
    ~Bullet();        //Distruttore
};

#endif // BULLET_H_INCLUDED
