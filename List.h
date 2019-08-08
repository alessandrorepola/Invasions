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

    List();                         //Costruttore di default
    GameEntity *GetFirst();         //Restituisce il puntatore al primo elemento della lista
    void Add(GameEntity*);          //Aggiunge alla lista gli oggetti salvati su file
    void Add(GameEntity*, double);  //Aggiunge un nuovo oggetto alla lista
    void Remove(GameEntity*);       //Rimuove l'oggetto specificato
    void Draw(WINDOW*);             //Disegna gli oggetti della lista
    void SetIter();                 //Imposta il puntatore iter
    void SetNext();                 //Sposta il puntatore iter al colpo successivo
    GameEntity *GetIter();          //Restituisce il puntatore iter
    bool EndList();                 //Controlla se l'iteratore e' alla fine della lista
    bool Empty();
    void DeleteList();              //Cancella gli elementi della lista
    Enemy *GetEnemy();              //Restituisce un puntatore di tipo Enemy
    Bullet *GetBullet();            //Restituisce un puntatore di tipo Bullet
    ~List();                        //Distruttore
};

#endif // LIST_H_INCLUDED
