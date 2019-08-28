//File bullet.h
#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include "Globals.h"
#include "GameEntity.h"
#include "Graphics/Window.h"

class Bullet : public GameEntity
{
    friend class List;

    void Draw() override;  //Disegna l'oggetto colpo sullo schermo

    public:

    void Move() override;      //Muove il colpo sparato
    bool Remove();     //Controlla se il colpo deve essere eliminato
    Bullet(int, int, int, Window*); //Costruttore che prende come argomento la riga e la colonna
    ~Bullet();        //Distruttore
};

#endif // BULLET_H_INCLUDED
