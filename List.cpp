/***********************************************
* File List.cpp                                *
* Implementazione dei metodi della classe List *
***********************************************/

#include "List.h"

List::List()
{
    start = clock();
}

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

void List::DeleteList()
{
    for (it = EntityList.begin(); it != EntityList.end(); it++)
    {
        delete *it;
    }
}

//Rimuove l'oggetto specificato come argomento dalla lista
void List::Remove(GameEntity* remobj)
{
    it = EntityList.begin();
    while(it != EntityList.end())
    {
        if (GetIter() == remobj)
        {
            EntityList.erase(it++);
            break;
        }
    }
}

//Per lo spostamento sullo schermo degli oggetti della lista
void List::Move()
{
    //Controllo se ci sono oggetti
    if (EntityList.empty())
    {
        return;
    }
    else
    {
        it = EntityList.begin();
        while(it != EntityList.end())
        {
            //Se la Funzione Move dell'oggetto restituisce false
            //L'oggetto deve essere rimosso dalla lista
            if (!(GetIter()->Move()))
            {
                EntityList.erase(it++);
            }
            else
            {
                ++it;
            }
        }
    }
}

//Disegna i colpi
void List::Draw (WINDOW *win)
{
    it = EntityList.begin();
    while(it != EntityList.end())
    {
        GetIter()->Draw(win);
        it++;
    }
}

GameEntity *List::GetIter()
{
    return *it;
}

List::~List()
{

}
