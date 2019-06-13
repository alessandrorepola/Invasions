#ifndef MOTHERSHIP_H_INCLUDED
#define MOTHERSHIP_H_INCLUDED

#include "Enemy.h"
#include "Cannon.h"

class Mothership
{
    Enemy *first;  //Puntatore al primo nemico generato
    Enemy *last;   //Puntatore all'utimo nemico generato
    Enemy *iter;   //Puntatore mobile
    clock_t start; //Per cronometrare il tempo
    void FuseEnemy(); //Unisce due navicelle aliene che si scontrano

    public:

    Mothership();
    Enemy *GetFirst();
    void AddEnemy();           //Genera un nuovo nemico
    void RemoveFirst();        //Remuove il primo nemico della lista
    void RemoveLast();         //Remuove l'ultimo nemico della lista
    void RemoveEnemy(Enemy*);  //Rimuove il nemico specificato
    void MoveEnemy();          //Muove i nemici
    void Draw(WINDOW*);        //Disegna i nemici
    void EnemyShoot(Cannon &); //Sparo dei nemici
    void SetIter();            //Imposta il puntatore iter
    void SetIter(Enemy *);     //Imposta il puntatore iter
    void NextEnemy();          //Sposta il puntatore iter al colpo successivo
    Enemy *GetIter();          //Restituisce il puntatore iter
    ~Mothership();
};

#endif // MOTHERSHIP_H_INCLUDED
