//File bullet.h
#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include "Globals.h"
#include "GameEntity.h"

class Bullet : public GameEntity
{
    friend class Cannon;

    Bullet *next;     //Puntatore al colpo successivo
    Bullet *prev;     //Puntatore al colpo precedente
    Bullet(int, int, int); //Costruttore che prende come argomento la riga e la colonna
    void Move() override;      //Muove il colpo sparato
    int id;           //Identifica l'appartenenza del colpo

    public:

    Bullet();
    Bullet(Bullet&);   //Costruttore che ricrea un colpo con le caratteristiche di quello salvato su file
    Bullet *GetPrev();//Restituisce il puntatore al colpo precedente
    Bullet *GetNext();//Restituisce il puntatore al colpo successivo
    int GetId();      //Restituisce l'id del colpo
    ~Bullet();        //Distruttore
};

#endif // BULLET_H_INCLUDED
