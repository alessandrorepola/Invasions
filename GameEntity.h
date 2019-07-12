/**************************************************
* Questo file contiene una classe astratta pura,  *
* per definire le caratteristiche standard delle  *
* entità del gioco come i nemici la navicella del *
* giocatore ecc...                                *
**************************************************/

#ifndef GAMEENTITY_H_INCLUDED
#define GAMEENTITY_H_INCLUDED

#include "Globals.h"

class GameEntity
{
    public:
    int row;
    int column;
    int life;
    clock_t start;
    GameEntity();
    virtual ~GameEntity();
    virtual int GetRow();
    virtual int GetColumn();
    virtual int GetLife();
    virtual void Move() = 0;

};

#endif // GAMEENTITY_H_INCLUDED
