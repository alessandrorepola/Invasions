/********************************************
* File Bonus.cpp                            *
* Implementazione metodi della classe Bonus *
********************************************/

#include "Bonus.h"

Bonus::Bonus(Window *win):
    GameEntity(int(), int(), int(), int(), win)
{
    //Genera il lato in cui viene generato il bonus
    SetSide();

    //Imposta il tipo di bonus
    SetType();

    //Genera le coordinate iniziali
    CoordGeneration();

    //Imposto la direzione
    SetDirection();
}

//Genera un bonus
bool Bonus::Generation()
{
    if(rand()%/*19785*/2 == 0)
    {
        return true;
    }
    return false;
}

//Imposta il tipo di bonus
void Bonus::SetType()
{
    type = rand()%(SHIELD+1);
}

//Imposta il lato dello schermo in cui viene generato il bonus
void Bonus::SetSide()
{
    side = rand()%CONSOLE_SIDE;
}

//Verifiva se deve essere eliminato
bool Bonus::Remove()
{
    //Faccio un lungo controllo per verificare quando il bonus
    //arriva al lato opposto della schermata,
    //in tal caso dovra, quindi, essere eliminato
    if (((row < win->GetY()) && (direction == UP)) ||
        ((row >= win->GetHeight()-1) && (direction == DOWN)) ||
        ((column <= win->GetX()) && (direction == LEFT)) ||
        ((column >= win->GetWidth()-1) && (direction == RIGHT)))
    {
        return true;
    }
    return false;
}

void Bonus::Move()
{
    clock_t time;
    double diff = INIT;

    //Controllo il tempo trascorso dall'ultimo colpo
    time = clock();
    diff = (double)(time-start);
    diff = diff/CLOCKS_PER_SEC;

    //Controllo il tempo trascorso dall'ultimo spostamento
    if (diff >= BONUS_SPEED)
    {
        start = time;

        //Modifico le coordinate in base alla direzione
        switch (direction)
        {
            case UP:
                --row;
                break;

            case DOWN:
                ++row;
                break;

            case RIGHT:
                ++column;
                break;

            case LEFT:
                --column;
                break;
        }
    }
}

//Genera le posizioni iniziali
void Bonus::CoordGeneration()
{
    switch (side)
    {
        case UP:
            row = win->GetY();
            column = rand()%(win->GetWidth());
            break;

        case DOWN:
            row = win->GetHeight()-2;
            column = rand()%(win->GetWidth());
            break;

        case LEFT:
            column = win->GetX();
            row = rand()%(win->GetHeight());
            break;

        case RIGHT:
            column = win->GetWidth()-2;
            row = rand()%(win->GetHeight());
            break;
    }
}

//Imposta una direzione in cui si puo' spostare il bonus
void Bonus::SetDirection()
{
    //Controllo se il bonus si trova lungo il bordo superiore della console
    if (row <= win->GetY())
    {
        //Il bonus si dovra' spostare verso il basso
        direction = DOWN;
    }

    //Controllo se il bonus si trova lungo il bordo inferiore della console
    else if (row >= win->GetHeight()-2)
    {
        //Il bonus si dovra' spostare verso l'alto
        direction = UP;
    }

    //Controllo se il bonus si trova sul lato sinistro della console
    else if (column <= win->GetX())
    {
        //Allora si dovra' spostare verso destra
        direction = RIGHT;
    }

    //Controllo se il nemico si trova sul lato destro della console
    else if (column >= win->GetWidth())
    {
        //Verso sinistra
        direction = LEFT;
    }
}

//Disegno del Bonus
void Bonus::Draw()
{
    switch(type)
    {
        case LIFE:
            mvwprintw(win->GetWin(), row, column ,"L");
            break;

        case SHIELD:
            mvwprintw(win->GetWin(), row, column ,"S");
            break;
    }
}

Bonus::~Bonus() {}
