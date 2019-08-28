#ifndef ENIMY_H_INCLUDED
#define ENIMY_H_INCLUDED

#include "List.h"
#include "GameEntity.h"

class List;
class Enemy : public GameEntity
{
    friend class Mothership;

    clock_t lastBulletTime;
    int bulletDirection;
    double bulletGenerationTime;
    double generationTime;
    int side;               //Il lato iniziale da cui parte la navicella
    void CoordGeneration(); //Genera le posizioni iniziali del nemico
    void Draw()override;
    void SetDirection();    //Imposta una direzione in cui si puo' spostare la navicella
    void SetMovement();     //Sposta il nemico di una posizione in base alla direzione

    public:

    Enemy(Window*);                //Costruttore
    void Move() override;            //Muove il nemico
    bool CheckDie();        //Controlla se il nemico e stato distrutto
    double GetGenerationTime();
    void Shoot(List&);      //Sparo del Nemico
    ~Enemy();               //Distruttore
};

#endif // ENIMY_H_INCLUDED
