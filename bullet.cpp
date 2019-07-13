//File bullet.cpp
#include "Bullet.h"

Bullet::Bullet()
{
    next = NULL;
    prev = NULL;
}

//Costruttore che ricrea un colpo con le caratteristiche di quello salvato su file
Bullet::Bullet(Bullet &bull)
{
    //Inizializzo le coordinate del colpo
    row = bull.GetRow();
    column = bull.GetColumn();
    direction = bull.GetDirection();

    //Inizializzo il tempo
    start = bull.start;
}

//Costruttore che posiziona il colpo
Bullet::Bullet(int r, int c, int d)
{
    next = NULL;
    prev = NULL;

    //Inizializzo le coordinate del colpo
    row = r;
    column = c;
    direction = d;

    //Inizializzo il tempo
    start = clock();
}

//Sposta il colpo
bool Bullet::Move()
{
    clock_t time;
    double diff = INIT;

    //Controllo il tempo trascorso dall'ultimo colpo
    time = clock();
    diff = (double)(time-start);
    diff = diff/CLOCKS_PER_SEC;

    //Controllo se si può muovere
    if (diff >= BULLET_SPEED)
    {
        start = time;
        if (direction == NORTH)
        {
            --row;
        }
        else
        {
            ++row;
        }
    }
    //Restituisce il valore di Remove() negato
    //quindi , se restituisce vero, Move() restituirà falso
    //Perchè il colpo non deve più spostarsi ma essere cancellato
     return !Remove();
}

//DIsegna il colpo
void Bullet::Draw(WINDOW *win)
{
    if (GetDirection() == NORTH)
    {
        wattrset(win, COLOR_PAIR(RED));
        mvwaddch(win, GetRow(), GetColumn(), ACS_DIAMOND);
        wattrset(win, COLOR_PAIR(WHITE));
    }
    else
    {
        wattrset(win, COLOR_PAIR(BLUE));
        mvwaddch(win, GetRow(), GetColumn(), ACS_LANTERN);
        wattrset(win, COLOR_PAIR(WHITE));
    }
}

//Restituisce l'id del colpo
bool Bullet::Remove()
{
    //Se va verso l'alto
    if ((GetRow() < START_XY) || (GetRow() >= GAME_WIN_HEIGHT))
    {
        return true;
    }
    return false;
}

//Restituisce il puntatore al colpo precedente
Bullet* Bullet::GetPrev()
{
    return prev;
}

//Restituisce il puntatore al colpo successivo
Bullet* Bullet::GetNext()
{
    return next;
}

//Distruttore
Bullet::~Bullet()
{
    next = NULL;
    prev = NULL;
}
