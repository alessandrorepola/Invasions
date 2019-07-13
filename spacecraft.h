//File spacecraft.h
#ifndef SPACECRAFT_H_INCLUDED
#define SPACECRAFT_H_INCLUDED

#include "GameEntity.h"
#include "List.h"
#include "Graphics/Window.h"
#include "Graphics/Menu.h"

class Spacecraft : public GameEntity
{
    int bulletDirection;
    double bulletGenerationTime;

    public:

    Spacecraft();          //Costruttore
    bool Move() override;        //sposta la navicella
    void DecreaseRow();
    void DecreaseColumn();
    void IncreaseRow();
    void IncreaseColumn();
    void CheckMove();      //Controlla lo spostamento della navicella
    void Shoot(List&);   //Spara il colpo
    void Draw(WINDOW*);    //Disegna la navicella
    bool DecreaseLife(int); //Decrementa la vita della navicella
    ~Spacecraft();         //Distruttore
};

#endif // SPACECRAFT_H_INCLUDED
