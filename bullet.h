//File bullet.h
#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include "Globals.h"
#include "GameEntity.h"
#include "Graphics/Window.h"

class Bullet : public GameEntity
{
    friend class List;

    Bullet *next;     //Puntatore al colpo successivo
    Bullet *prev;     //Puntatore al colpo precedente
    void Draw(WINDOW*) override;  //Disegna l'oggetto colpo sullo schermo

    public:

    Bullet();
    void Move(Window&) override;      //Muove il colpo sparato
    bool Remove(Window&);     //Controlla se il colpo deve essere eliminato
    Bullet(int, int, int); //Costruttore che prende come argomento la riga e la colonna
    Bullet(Bullet&);   //Costruttore che ricrea un colpo con le caratteristiche di quello salvato su file
    Bullet *GetPrev();//Restituisce il puntatore al colpo precedente
    Bullet *GetNext();//Restituisce il puntatore al colpo successivo
    ~Bullet();        //Distruttore
};

#endif // BULLET_H_INCLUDED
