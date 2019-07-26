//File spacecraft.h
#ifndef SPACECRAFT_H_INCLUDED
#define SPACECRAFT_H_INCLUDED

#include "GameEntity.h"
#include "List.h"
#include "Bullet.h"
#include "Graphics/Window.h"
#include "Graphics/Menu.h"

class Spacecraft : public GameEntity
{
    int bulletDirection;
    double bulletGenerationTime;

    public:

    Spacecraft(Window&);          //Costruttore
    void Move(Window&) override;        //sposta la navicella
    void DecreaseRow();
    void DecreaseColumn();
    void IncreaseRow();
    void IncreaseColumn();
    void CheckMove();      //Controlla lo spostamento della navicella
    void Shoot(List&, Window&);   //Spara il colpo
    void Draw(WINDOW*) override;    //Disegna la navicella
    ~Spacecraft();         //Distruttore
};

#endif // SPACECRAFT_H_INCLUDED
