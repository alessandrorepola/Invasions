/***********************************************
* File List.cpp                                *
* Implementazione dei metodi della classe List *
***********************************************/

#include "List.h"

List::List()
{
    start = clock();
}

//Agginge alla lista gli oggetti salvati sul file dall'ultima partita salvata
void List::Add(GameEntity* obj)
{
    EntityList.push_back(obj);
}

//Aggiunge nuovi oggetti alla lista
//Calcolando anche il tempo trascorso dall'ultimo oggetto aggiunto
void List::Add(GameEntity *obj, double generation_time)
{
    clock_t time;
    double diff = INIT;

    //Controllo il tempo trascorso dall'ultimo colpo
    time = clock();
    diff = (double)(time-start);
    diff = diff/CLOCKS_PER_SEC;

    //Controllo se si può muovere
    if (diff >= generation_time)
    {
        start = time;
        EntityList.push_back(obj);
    }
}

//Trasferisce il contenuto di una lista in un altra
void List::Transfer(List *TempList)
{
    EntityList.splice(EntityList.begin(), TempList->EntityList);
}

bool List::Empty()
{
    if (EntityList.empty())
    {
        return true;
    }
    return false;
}

void List::DeleteList()
{
    for (it = EntityList.begin(); it != EntityList.end(); it++)
    {
        delete *it;
    }
}

//Rimuove l'oggetto specificato come argomento dalla lista
void List::Remove(GameEntity* obj)
{
    SetIter();
    while(!EndList())
    {
        if (GetIter() == obj)
        {
            EntityList.erase(it++);
            break;
        }
        SetNext();
    }
}

//Disegna i colpi
void List::Draw ()
{
    for(auto *obj : EntityList)
    {
        obj->Draw();
    }
}

void List::SetIter()
{
    it = EntityList.begin();
}

void List::SetNext()
{
    ++it;
}

GameEntity *List::GetIter()
{
    return *it;
}

Enemy *List::GetEnemy()
{
    return (static_cast <Enemy*> (*it));
}

Bullet *List::GetBullet()
{
    return (static_cast <Bullet*> (*it));
}

bool List::EndList()
{
    if (it != EntityList.end())
    {
        return false;
    }
    return true;
}

List::~List()
{

}
