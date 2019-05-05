//File spacecraft.h
#ifndef SPACECRAFT_H_INCLUDED
#define SPACECRAFT_H_INCLUDED

#include "Cannon.h"

class Spacecraft
{
    int column;     //coordinata X
    int row;        //coordinata Y
    int life;       //vita della navicella

    public:

    Spacecraft();        //costruttore
    bool Move(int);      //sposta la navicella
    void CheckMove();    //Controlla lo spostamento della navicella
    bool Shoot(Cannon&); //spara il colpo
    void Draw();         //disegna la navicella
    ~Spacecraft();       //distruttore
};

#endif // SPACECRAFT_H_INCLUDED
