#ifndef ENIMY_H_INCLUDED
#define ENIMY_H_INCLUDED

#include "Invasions.h"

class Enemy
{
    friend class Mothership;

    int direction;          //La direzione in cui si sposta
    int row;                //Riga del nemico
    int column;             //Colonna del nemico
    int side;               //Il lato iniziale da cui parte la navicella
    Enemy *next;            //Puntatore all'oggetto successivo
    Enemy *prev;            //Puntatore all'oggetto precedente
    clock_t start;          //Misura il tempo dall'ultimo nemico generato
    void CoordGeneration(); //Genera le posizioni iniziali del nemico
    void Move();            //Muove il nemico
    void SetDirection();    //Imposta una direzione in cui si puo' spostare la navicella
    void Movement();        //Sposta il nemico di una posizione in base alla direzione

    public:

    Enemy();                //Costruttore
    ~Enemy();               //Distruttore
};

#endif // ENIMY_H_INCLUDED
