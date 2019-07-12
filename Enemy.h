#ifndef ENIMY_H_INCLUDED
#define ENIMY_H_INCLUDED

#include "Globals.h"
#include "GameEntity.h"

class Enemy : public GameEntity
{
    friend class Mothership;

    int direction;          //La direzione in cui si sposta
    int side;               //Il lato iniziale da cui parte la navicella
    Enemy *next;            //Puntatore all'oggetto successivo
    Enemy *prev;            //Puntatore all'oggetto precedente
    clock_t start;          //Misura il tempo dall'ultimo nemico generato
    void CoordGeneration(); //Genera le posizioni iniziali del nemico
    void Move() override;            //Muove il nemico
    void SetDirection();    //Imposta una direzione in cui si puo' spostare la navicella
    void SetMovement();     //Sposta il nemico di una posizione in base alla direzione

    public:

    Enemy();                //Costruttore
    bool CheckDie();        //Controlla se il nemico e stato distrutto
    ~Enemy();               //Distruttore
};

#endif // ENIMY_H_INCLUDED
