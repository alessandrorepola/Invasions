/************************************************
* Questo file contiene una classe astratta, per *
* definire le caratteristiche standard delle    *
* entità del gioco come i nemici la navicella   *
* del giocatore e i colpi                       *
************************************************/

#ifndef GAMEENTITY_H_INCLUDED
#define GAMEENTITY_H_INCLUDED

#include "Globals.h"
#include "Graphics/Window.h"

class GameEntity
{
    protected:

    int row;
    int column;
    int life;
    int direction;
    clock_t start;

    public:

    GameEntity();
    virtual ~GameEntity();
    virtual int GetRow();
    virtual int GetColumn();
    virtual int GetLife();
    virtual int GetDirection();
    virtual void DecreaseLife(int);
    virtual void Draw(WINDOW*) = 0;
    virtual void Move(Window&) = 0;

};

#endif // GAMEENTITY_H_INCLUDED
