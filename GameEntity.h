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

    int row;        //Riga dell'oggetto
    int column;     //Colonna dell'oggetto
    int life;       //Punti vita
    int direction;  //Direzione in cui si sposta l'oggetto
    clock_t start;  //Tempo trascorso dall'esecuzione del programma alla creazione dell'oggetto
                    //In questo modo possiamo calcolarci la differenza di tempo per lo spostamento
    Window *win;    //Puntatore alla finestra in cui esiste l'oggetto

    public:

    GameEntity() = default;         //Costruttore di default
    GameEntity(int, int, int, int, Window*);
    virtual ~GameEntity();          //Distruttore virtuale
    virtual int GetRow();           //Restiruisce la riga dell'oggetto
    virtual int GetColumn();        //Restituisce la colonna dell'oggetto
    virtual int GetLife();          //Restituisce i punti vita dell'oggetto
    virtual int GetDirection();     //Restituisce la direzione
    virtual void DecreaseLife(int); //Decrementa la variabile life
    virtual void Draw() = 0;        //Per il disegno dell'oggetto
    virtual void Move() = 0;        //Per lo spaostamento dell'oggetto

};

#endif // GAMEENTITY_H_INCLUDED
