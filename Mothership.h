#ifndef MOTHERSHIP_H_INCLUDED
#define MOTHERSHIP_H_INCLUDED

#include "Enemy.h"

class Mothership
{
    Enemy *first;  //Puntatore al primo nemico generato
    Enemy *last;   //Puntatore all'utimo nemico generato
    Enemy *iter;   //Puntatore mobile
    clock_t start; //Per cronometrare il tempo

    public:

    Mothership();
    Enemy *GetFirst();
    void AddEnemy();           //Genera un nuovo nemico
    void RemoveFirst();        //Remuove il primo nemico della lista
    void RemoveLast();         //Remuove l'ultimo nemico della lista
    void RemoveEnemy(Enemy*);  //Rimuove il nemico specificato
    bool MoveEnemy();          //Muove i nemici
    void Draw();               //Disegna i nemici
    void SetIter();            //Imposta il puntatore iter
    void SetIter(Enemy *);     //Imposta il puntatore iter
    void NextEnemy();          //Sposta il puntatore iter al colpo successivo
    Enemy *GetIter();          //Restituisce il puntatore iter
    ~Mothership();
};

#endif // MOTHERSHIP_H_INCLUDED
