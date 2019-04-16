//File spacecraft.h
#ifndef SPACECRAFT_H_INCLUDED
#define SPACECRAFT_H_INCLUDED

#include "cannon.h"
#define LIFE 3
#define EXIT 0
#define MOVE 1
#define SHOT 2

class Spacecraft
{
    int column;     //coordinata X
    int row;        //coordinata Y
    int life;       //la vita della navicella

    public:

    Spacecraft();        //costruttore
    int Move(int);       //sposta la navicella
    void Shoot(Cannon&); //spara il colpo
    void Draw();         //disegna la navicella
    ~Spacecraft();       //distruttore
};

#endif // SPACECRAFT_H_INCLUDED
