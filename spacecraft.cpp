//File spacecraft.cpp
#include "spacecraft.h"

//Costruttore
Spacecraft::Spacecraft()
{
    life = LIFE;
    row = 15;
    column = 50;
}

//Movimeto della navicella
int Spacecraft::Move(int key)
{
    switch (key)
    {
        //tasti direzionali
        case KEY_UP:
        --row;
        break;

        case KEY_DOWN:
        ++row;
        break;

        case KEY_LEFT:
        --column;
        break;

        case KEY_RIGHT:
        ++column;
        break;

        case 'q':
        case 'Q':
            return EXIT;

        // Se non viene premuto nessun tasto o un altro tasto diverso dai precedenti esce
        case ERR:
        default:
            return ERR;

    }
    clear();
    Draw();
    return MOVE;
}

//Disegna la navicella
void Spacecraft::Draw ()
{
    mvprintw(row,column-2,"\\-^-/");
    refresh();
}

//Spara il colpo
void Spacecraft::Shot(Bullet *missile)
{
    //Controllo se la lista è vuota
    if (missile->next == NULL)
    {
        //creo un nuovo oggetto che rappresenta il primo colpo da sparare
        missile->next = new Bullet; //se è vuota indico al puntatore next della sentinella di puntare un nuovo oggetto
        missile->next->prev = missile; //il puntatore prev del nuovo oggetto punta alla sentinella
        missile->next->next = missile; //il puntatore next del nuovo oggetto
    }
}

//Distruttore
Spacecraft::~Spacecraft()
{
    return;
}
