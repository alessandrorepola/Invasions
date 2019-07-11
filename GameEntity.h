/**************************************************
* Questo file contiene una classe astratta pura,  *
* per definire le caratteristiche standard delle  *
* entità del gioco come i nemici la navicella del *
* giocatore ecc...                                *
**************************************************/

#ifndef GAMEENTITY_H_INCLUDED
#define GAMEENTITY_H_INCLUDED

class GameEntity
{
    int row;
    int column;
    int life;

    public:

    GameEntity();
    virtual ~GameEntity();
    int GetRow();
    int GetColumn();
    int GetLife();

};

#endif // GAMEENTITY_H_INCLUDED
