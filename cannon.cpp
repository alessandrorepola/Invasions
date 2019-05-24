//File cannon.cpp
#include "Cannon.h"

Cannon::Cannon()
{
    first = NULL;
    last = NULL;
    iter = NULL;
    start = clock();
}

//Restituisce il puntatore al primo elemento della lista
Bullet *Cannon::GetFirst()
{
    return first;
}

//Aggiunge un nuovo colpo
void Cannon::AddObject(int r, int c)
{
    clock_t time;
    double diff = INIT;

    //Controllo il tempo trascorso dall'ultimo colpo
    time = clock();
    diff = (double)(time-start);
    diff = diff/CLOCKS_PER_SEC;

    //Controllo se si può muovere
    if (diff >= BULLET_GENERATION_TIME)
    {
        start = time;
        Bullet *add = NULL;

        //Controllo se è il primo oggetto colpo
        if (first == NULL)
        {
            first = new Bullet(r,c); //Dichiaro il primo colpo
            last = first;           //last punterà al primo colpo
        }
        else
        {
            add = new Bullet(r,c); //Dichiaro un nuovo colpo
            add->prev = last;      //prev punterà a last che è il penultimo colpo
            last->next = add;      //Il puntatore next del colpo precedente punterà a quello attuale
            last = add;            //Aggiorno il puntatore last all'ultimo colpo
        }
    }
}

//Rimuove il primo colpo
void Cannon::RemoveFirst()
{
    Bullet *rm = NULL;

    //Controllo prima se ci sono dei colpi
    if (first == NULL)
        return;

    //Controllo se c'è solo un colpo sparato
    else if (first->next == NULL)
    {
        //Cancello il colpo e qualsiasi riferimento ad esso
        delete first;
        first = NULL;
        last = NULL;
    }

    //Nel caso ci siano più colpi sparati
    else
    {
        //Sposto il puntatore first un elemento più avanti e cancello il primo colpo
        rm = first;
        first = first->next;
        first->prev = NULL;
        delete rm;
    }
}

//Rimuove l'ultimo colpo
void Cannon::RemoveLast()
{
    Bullet *rm = NULL;

    //Controllo prima se ci sono dei colpi
    if (first == NULL)
        return;

    //Controllo se c'è solo un colpo sparato
    else if (first->next == NULL)
    {
        //Cancello il colpo e qualsiasi riferimento ad esso
        delete first;
        first = NULL;
        last = NULL;
    }

    //Nel caso ci siano più colpi sparati
    else
    {
        //Sposto il puntatore last indietro di un elemento e cancello l'ultimo colpo
        rm = last;
        last = last->prev;
        last->next = NULL;
        delete rm;
    }
}

//Rimuove un colpo specifico
void Cannon::RemoveObject(Bullet *pbull)
{
    //Controllo se ci sono colpi sparati
    if (first == NULL)
        return;

    //Controllo se è il primo colpo della lista
    else if (first == pbull)
        RemoveFirst();

    //Controllo se è l'ultimo colpo della lista
    else if (last == pbull)
        RemoveLast();

    //Altrimenti concateno il precedente e il successivo del colpo da cancellare tra di loro
    else
    {
        //Il successivo puntera' al precedente del colpo da cancellare
        pbull->next->prev = pbull->prev;

        //Il precedente invece andra' a puntare al successivo del colpo da cancellare
        pbull->prev->next = pbull->next;

        //Cancello il colpo
        delete pbull;
    }
}

//Muove i colpi
void Cannon::MoveObject()
{
    //Controllo se ci sono colpi
    if (first == NULL)
    {
        return;
    }
    else
    {
        first->Move();
    }

    //Controllo se il primo colpo è arrivato al bordo superiore della console e quindi deve essere cancellato
    if(first->row < INIT)
        RemoveFirst();
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

//Imposta il puntatore iter
void Cannon::SetIter()
{
    iter = first;
}

void Cannon::SetIter(Bullet *pbull)
{
    iter = pbull;
}

//Imposta il puntatore iter al colpo successivo
void Cannon::NextBullet()
{
    if (iter != NULL)
    {
        iter = iter->next;
    }
}

//Restituisce il valore di iter
Bullet *Cannon::GetIter()
{
    return iter;
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
