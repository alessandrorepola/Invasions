//File spacecraft.h
#ifndef SPACECRAFT_H_INCLUDED
#define SPACECRAFT_H_INCLUDED

#include "Cannon.h"
#include "Graphics/Window.h"
#include "Graphics/Menu.h"

class Spacecraft
{
    int column;     //coordinata X
    int row;        //coordinata Y
    int life;       //vita della navicella

    public:

    Spacecraft();          //Costruttore
    int GetRow();          //Restituisce la riga della navicella
    int GetColumn();       //Restituisce la colonna della navicella
    int Move(int);        //sposta la navicella
    void CheckMove();      //Controlla lo spostamento della navicella
    void Shoot(Cannon&);   //Spara il colpo
    void Draw(WINDOW*);    //Disegna la navicella
    bool DecreseLife(int); //Decrementa la vita della navicella
    int GetLife();         //Restituisce la vita della navicella
    ~Spacecraft();         //Distruttore
};

#endif // SPACECRAFT_H_INCLUDED
