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

    Spacecraft();          //costruttore
    int GetRow();          //restituisce la riga della navicella
    int GetColumn();       //Restituisce la colonna della navicella
    bool Move(int);        //sposta la navicella
    void CheckMove();      //Controlla lo spostamento della navicella
    void Shoot(Cannon&);   //spara il colpo
    void Draw();           //disegna la navicella
    bool DecreseLife(int); //decrementa la vita della navicella
    ~Spacecraft();         //distruttore
};

#endif // SPACECRAFT_H_INCLUDED
