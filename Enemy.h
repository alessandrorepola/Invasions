#ifndef ENIMY_H_INCLUDED
#define ENIMY_H_INCLUDED

#include "Globals.h"
#include "GameEntity.h"

class Enemy : public GameEntity
{
    friend class Mothership;

    double generationTime;
    int side;               //Il lato iniziale da cui parte la navicella
    Enemy *next;            //Puntatore all'oggetto successivo
    Enemy *prev;            //Puntatore all'oggetto precedente
    clock_t start;          //Misura il tempo dall'ultimo nemico generato
    void CoordGeneration(); //Genera le posizioni iniziali del nemico
    bool Move() override;            //Muove il nemico
    void Draw(WINDOW*)override;
    void SetDirection();    //Imposta una direzione in cui si puo' spostare la navicella
    void SetMovement();     //Sposta il nemico di una posizione in base alla direzione

    public:

    Enemy();                //Costruttore
    bool CheckDie();        //Controlla se il nemico e stato distrutto
    double GetGenerationTime();
    ~Enemy();               //Distruttore
};

#endif // ENIMY_H_INCLUDED
