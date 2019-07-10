//File Mothership.cpp
#include "Mothership.h"

//Costruttore
Mothership::Mothership()
{
    first = NULL;
    last = NULL;
    iter = NULL;
    start = clock();
}

Enemy *Mothership::GetFirst()
{
    return first;
}

//Aggiunge un nuovo oggetto nemico
void Mothership::AddEnemy()
{
    clock_t time;
    double diff = INIT;

    //Controllo il tempo trascorso dall'ultimo colpo
    time = clock();
    diff = (double)(time-start);
    diff = diff/CLOCKS_PER_SEC;

    //Controllo se si pu� muovere
    if (diff >= ENEMY_GENERATION_TIME)
    {
        start = time;
        Enemy *add = NULL;

         //Controllo se � il primo oggetto
        if (first == NULL)
        {
            first = new Enemy();     //Dichiaro il primo nemico
            last = first;            //last punter� al primo nemico
        }
        else
        {
            add = new Enemy();     //Dichiaro un nuovo nemico
            add->prev = last;      //prev punter� a last che � il penultimo nemico generato
            last->next = add;      //Il puntatore next del nemico precedente punter� a quello attuale
            last = add;            //Aggiorno il puntatore last all'ultimo nemico genenato
        }
    }
}

//Rimuove il primo nemico generato
void Mothership::RemoveFirst()
{
    Enemy *rm = NULL;

    //Controllo prima se ci sono dei nemici
    if (first == NULL)
        return;

    //Controllo se c'� solo un nemico
    else if (first->next == NULL)
    {
        //Cancello il nemico e qualsiasi riferimento ad esso
        delete first;
        first = NULL;
        last = NULL;
    }

    //Nel caso ci siano pi� nemici
    else
    {
        //Sposto il puntatore first un elemento pi� avanti e cancello il primo elemento
        rm = first;
        first = first->next;
        first->prev = NULL;
        delete rm;
    }
}

//Rimuove l'ultimo nemico generato
void Mothership::RemoveLast()
{
    Enemy *rm = NULL;

    //Controllo prima se ci sono dei nemici
    if (first == NULL)
        return;

    //Controllo se c'� solo un nemico
    else if (first->next == NULL)
    {
        //Cancello il nemico e qualsiasi riferimento ad esso
        delete first;
        first = NULL;
        last = NULL;
    }

    //Nel caso ci siano pi� nemici
    else
    {
        //Sposto il puntatore last indietro di un elemento e cancello l'ultimo nemico generato
        rm = last;
        last = last->prev;
        last->next = NULL;
        delete rm;
    }
}

//Rimuove un nemico
void Mothership::RemoveEnemy(Enemy *pobj)
{
    //Controllo se ci sono nemici
    if (first == NULL)
        return;

    //Sposto l'iteratore al nemico successivo della lista
    //In questo modo quando verr� cancellato l'oggetto nemico stesso iter non punter� a NULL
    NextEnemy();

    //Controllo se � il primo nemico della lista
    if (first == pobj)
        RemoveFirst();

    //Controllo se � l'ultimo nemico della lista
    else if (last == pobj)
        RemoveLast();

    //Altrimenti concateno il precedente e il successivo del nemico da cancellare tra di loro
    else
    {
        //Il successivo puntera' al precedente del nemico da cancellare
        pobj->next->prev = pobj->prev;

        //Il precedente invece andra' a puntare al successivo del nemico da cancellare
        pobj->prev->next = pobj->next;

        //Cancello il nemico
        delete pobj;
    }
}

//Muove il nemico
void Mothership::MoveEnemy()
{
    //Controllo se ci sono nemici
    if (first == NULL)
        return;
    else
    {
        first->Move();
    }
}

//Gestisce lo sparo dei nemici
void Mothership::EnemyShoot(Cannon &c)
{
    for(SetIter(); GetIter()!= NULL; NextEnemy())
    {
        //Scelgo una navicella random da cui sparare
        if (rand()%12==0)
        {
            //Spara il colpo
            c.AddObject(GetIter()->GetRow()+1, GetIter()->GetColumn(), ENEMY);
            c.MoveObject();
        }
    }
}

//Disegna tutti i nemici
void Mothership::Draw (WINDOW *win)
{
    Enemy *d = first;
    while(d != NULL)
    {
        wattron(win, COLOR_PAIR(GREEN));
        mvwprintw(win, d->row, d->column-1 ,"\\0/");
        wattroff(win, COLOR_PAIR(GREEN));
        d = d->next;
    }
}

//Imposta il puntatore iter
void Mothership::SetIter()
{
    iter = first;
}

//Imposta il puntatore iter
void Mothership::SetIter(Enemy *palien)
{
    iter = palien;
}

//Imposta il puntatore iter al nemico successivo
void Mothership::NextEnemy()
{
    if (iter == NULL)
        return;

    iter = iter->next;
}

//Restituisce il valore di iter
Enemy *Mothership::GetIter()
{
    return iter;
}

//Unisce i nemici tra di loro
void Mothership::FuseEnemy()
{
    //TO DO
}

//Cancello gli elementio della lista
void Mothership::DeleteList()
{
    //Puntatore per la deallocazione della memoria
    Enemy *del = first;

    //Puntatore temporaneo
    Enemy *tmp = first;

    //Rilascio al sistema tutta lamemoria ancora allocata
    while (del!=NULL)
    {
        tmp = del->next; //A tmp assegno l'oggetto successivo a quello da cancellare
        delete del;      //Cancello l'oggetto
        del = tmp;       //A del riassegno il prossimo oggetto da cancellare se esiste
    }
}

//Distruttore
Mothership::~Mothership()
{
    first = NULL;
    last = NULL;
    iter = NULL;
}
