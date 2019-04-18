//File cannon.cpp
#include "cannon.h"

Cannon::Cannon()
{
    first = NULL;
    last = NULL;
    start = clock();
}

//Aggiunge un nuovo colpo
void Cannon::AddBullet(int r, int c)
{
    clock_t time;
    double diff = INIT;

    //Controllo il tempo trascorso dall'ultimo colpo
    time = clock();
    diff = (double)(time-start);
    diff = diff/CLOCKS_PER_SEC;

    //Controllo se si pu� muovere
    if (diff >= BULLET_GENERATION_TIME)
    {
        start = time;
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

//Muove i colpi
void Cannon::MoveBullet()
{
    //Controllo se ci sono colpi
    if (first == NULL)
        return;
    else
    {
        first->Move();
    }

    //Controllo se il colpo � arrivato al bordo superiore dello schermo e quindi deve essere cancellato
    if(first->row<=INIT)
        RemoveBullet();
}

//Disegna i colpi
void Cannon::Draw ()
{
    Bullet *d = first;
    while(d != NULL)
    {
        mvprintw(d->row,d->column,"*");
        d = d->next;
    }
}

//Distruttore
Cannon::~Cannon()
{
    //Puntatore per la deallocazione della memoria
    Bullet *del = first;

    //Puntatore di appoggio
    Bullet *tmp = first;

    //Rilascio al sistema tutta lamemoria ancora allocata
    while (del!=NULL)
    {
        tmp = del->next; //A tmp assegno il colpo successivo a quello da cancellare
        delete del;      //Cancello il colpo
        del = tmp;       //A del riassegno il prossimo colpo da cancellare
    }
}
