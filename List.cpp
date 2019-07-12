/***********************************************
* File List.cpp                                *
* Implementazione dei metodi della classe List *
***********************************************/

#include "List.h"

List::List()
{
    start_enemy = clock();
    start_player = clock();
}

void List::Add(int r, int c, int id)
{
    clock_t time;
    double diff = INIT;
    double generation_time;

    //Controllo il tempo trascorso dall'ultimo colpo
    time = clock();

    if (id == PLAYER)
    {
        generation_time = TIME_PLAYER_BULLET;
        diff = (double)(time-start_player);
    }
    else
    {
        generation_time = TIME_ENEMY_BULLET;
        diff = (double)(time-start_enemy);
    }
    diff = diff/CLOCKS_PER_SEC;

    //Controllo se si può muovere
    if (diff >= generation_time)
    {
        if (id == PLAYER)
        {
            start_player = time;
        }
        else
        {
            start_enemy = time;
        }
        Bullet *add = new Bullet(r,c,id);
        EntityList.push_back(add);
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
        if ((*it)== remobj)
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
            (*it)->Move();
            it++;
        }
    }

    for (it = EntityList.begin(); it != EntityList.end(); it++)
    {
//        if ((*it)->id == PLAYER)
        {
            //Controllo se il colpo è arrivato al bordo superiore della console e quindi deve essere cancellato
            if((*it)->GetRow() < START_XY)
                Remove(*it);
        }
        /*else
        {
            //Controllo se il colpo è arrivato al bordo inferiore della console e quindi deve essere cancellato
            if(it->GetRow() >= GAME_WIN_HEIGHT)
                RemoveObject(it);
        }*/
    }
}

//Disegna i colpi
void List::Draw (WINDOW *win)
{
    it = EntityList.begin();
    while(it != EntityList.end())
    {
        //if (d->GetId() == PLAYER)
        {
            wattrset(win, COLOR_PAIR(RED));
            mvwaddch(win, (*it)->row, (*it)->column, ACS_DIAMOND);
            wattrset(win, COLOR_PAIR(WHITE));
        }
        /*else
        {
            wattrset(win, COLOR_PAIR(BLUE));
            mvwaddch(win, d->row, d->column, ACS_LANTERN);
            wattrset(win, COLOR_PAIR(WHITE));
        }*/
        it++;
    }
}

List::~List()
{

}
