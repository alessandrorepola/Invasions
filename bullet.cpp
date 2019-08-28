//File bullet.cpp
#include "Bullet.h"

//Costruttore che posiziona il colpo
Bullet::Bullet(int row, int column, int direction, Window *win):
    GameEntity(row, column, BULLET_DAMAGE, direction, win)
{}

//Sposta il colpo
void Bullet::Move()
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
}

//Disegna il colpo
void Bullet::Draw()
{
    if (GetDirection() == NORTH)
    {
        wattrset(win->GetWin(), COLOR_PAIR(RED));
        mvwaddch(win->GetWin(), GetRow(), GetColumn(), ACS_DIAMOND);
        wattrset(win->GetWin(), COLOR_PAIR(WHITE));
    }
    else
    {
        wattrset(win->GetWin(), COLOR_PAIR(BLUE));
        mvwaddch(win->GetWin(), GetRow(), GetColumn(), ACS_LANTERN);
        wattrset(win->GetWin(), COLOR_PAIR(WHITE));
    }
}

//Restituisce l'id del colpo
bool Bullet::Remove()
{
    //Se va verso l'alto
    if ((GetRow() < win->GetY()) || (GetRow() >= win->GetHeight()-1))
    {
        return true;
    }
    return false;
}

//Distruttore
Bullet::~Bullet()
{
}
