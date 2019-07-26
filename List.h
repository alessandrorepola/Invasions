#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <list>
#include <iostream>
#include "Enemy.h"
#include "Bullet.h"
#include "GameEntity.h"

class Enemy;
class List
{
    std::list <GameEntity*> EntityList;
    std::list <GameEntity*>::iterator it;
    clock_t start; //Per cronometrare il tempo trascorso dall'ultimo oggetto generato

    public:

    List();
    GameEntity *GetFirst();         //Restituisce il puntatore al primo elemento della lista
    void Add(GameEntity*, double);   //Genera un nuovo colpo con le sue coordinate
    void Remove(GameEntity*); //Rimuove il colpo specificato
    void Move();          //Muove i colpi
    void Move(List&);          //Muove i colpi
    void Draw(WINDOW*);         //Disegna i colpi
    void SetIter();             //Imposta il puntatore iter
    void SetNext();          //Sposta il puntatore iter al colpo successivo
    GameEntity *GetIter();          //Restituisce il puntatore iter
    bool EndList();
    void DeleteList();          //Cancella gli elementi della lista
    Enemy *GetEnemy();
    Bullet *GetBullet();
    ~List();                  //Distruttore*/
};

#endif // LIST_H_INCLUDED
