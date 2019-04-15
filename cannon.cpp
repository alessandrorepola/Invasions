//File cannon.cpp
#include "bullet.h"
#include "cannon.h"

Cannon::Cannon()
{
    first = NULL;
    last = NULL;
    iter = NULL;
}

//Aggiunge un nuovo colpo
void Cannon::AddBullet(int r, int c)
{
    Bullet *add = NULL;

    //Controllo se � il primo oggetto colpo
    if (first == NULL)
    {
        first = new Bullet(r,c); //Dichiaro il primo colpo
        last = first;           //last punter� al primo colpo
    }
    else
    {
        add = new Bullet(r,c); //Dichiaro un nuovo colpo
        add->prev = last;      //prev punter� a last che � il penultimo colpo
        last->next = add;      //Il puntatore next del colpo precedente punter� a quello attuale
        last = add;            //Aggiorno il puntatore last all'ultimo colpo
    }
}

//Rimuove il primo colpo
void Cannon::RemoveBullet()
{
    Bullet *rm = NULL;

    //Controllo prima se ci sono dei colpi
    if (first == NULL)
        return;

    //Controllo se c'� solo un colpo sparato
    else if (first->next == NULL)
    {
        //Cancello il colpo e qualsiasi riferimento ad esso
        delete first;
        first = NULL;
        last = NULL;
    }

    //Nel caso ci siano pi� colpi sparati
    else
    {
        //Sposto il puntatore first un elemento pi� avanti e cancello il primo colpo
        rm = first;
        first = first->next;
        first->prev = NULL;
        delete rm;
    }
}
