#ifndef MOTHERSHIP_H_INCLUDED
#define MOTHERSHIP_H_INCLUDED

#include "Enemy.h"

class Mothership
{
    Enemy *first;  //Puntatore al primo nemico generato
    Enemy *last;   //Puntatore all'utimo nemico generato
    clock_t start; //Per cronometrare il tempo

    public:

    Mothership();
    void AddEnemy();            //Genera un nuovo nemico
    void RemoveFirst();         //Remuove il primo nemico della lista
    void RemoveLast();          //Remuove l'ultimo nemico della lista
    void RemoveEnemy(Enemy*);   //Rimuove il nemico specificato
    void MoveEnemy();           //Muove i nemici
    void Draw();                //Disegna i nemici
    ~Mothership();
};

#endif // MOTHERSHIP_H_INCLUDED
