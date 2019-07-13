#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "GameEntity.h"
#include "Bullet.h"
#include "Enemy.h"
//#include "Globals.h"
#include <iostream>
#include <list>

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
    void Draw(WINDOW*);         //Disegna i colpi
    void SetFirst(GameEntity*);    //Imposta il primo colpo letto dal file
    void SetLast(GameEntity*);    //Imposta il primo colpo letto dal file
    void SetIter();             //Imposta il puntatore iter
    void SetIter(GameEntity*);     //Imposta il puntatore iter
    void Next();          //Sposta il puntatore iter al colpo successivo
    GameEntity *GetIter();          //Restituisce il puntatore iter
    void DeleteList();          //Cancella gli elementi della lista
    ~List();                  //Distruttore*/
};

#endif // LIST_H_INCLUDED
