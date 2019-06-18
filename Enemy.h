#ifndef ENIMY_H_INCLUDED
#define ENIMY_H_INCLUDED

#include "Globals.h"

class Enemy
{
    friend class Mothership;

    int direction;          //La direzione in cui si sposta
    int row;                //Riga del nemico
    int column;             //Colonna del nemico
    int side;               //Il lato iniziale da cui parte la navicella
    int life;               //Vita del nemico
    Enemy *next;            //Puntatore all'oggetto successivo
    Enemy *prev;            //Puntatore all'oggetto precedente
    clock_t start;          //Misura il tempo dall'ultimo nemico generato
    void CoordGeneration(); //Genera le posizioni iniziali del nemico
    void Move();            //Muove il nemico
    void SetDirection();    //Imposta una direzione in cui si puo' spostare la navicella
    void Movement();        //Sposta il nemico di una posizione in base alla direzione

    public:

    Enemy();                //Costruttore
    int GetRow();           //Restituisce il valore della riga del nemico
    int GetColumn();        //Restituisce la colonna del nemico
    int GetLife();          //Rstituisce la vita restante del nemico
    bool CheckDie();        //Controlla se il nemico e stato distrutto
    ~Enemy();               //Distruttore
};

#endif // ENIMY_H_INCLUDED
