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
    while(TRUE)
    {


        //Controllo se la lista è vuota
        if (missile == NULL)
        {
            //creo un nuovo oggetto che rappresenta il primo colpo da sparare
            missile = new Bullet;     //se il puntatore è null crei il primo colpo da sparare
            missile->first = missile; //il puntatore first punta il primo colpo sparato
            missile->row = row-1;     //alla riga del primo colpo indico la riga della navicella decrementete di uno
            missile->column = column; //alla colonna indico la stessa colonna della navicella
            Draw();
            missile->PrintBlow();
        }
        else
        {
            Bullet *tmp;
            for (tmp = missile->first; tmp->next!=NULL; tmp = tmp->next)
            {
                if (tmp == missile->first)
                {
                    missile->first->row = row-2;
                    missile->first->column = column;
                    if (missile->first->row < 0)
                    {
                        tmp = missile->first->next;
                        delete missile->first;
                        missile->first = tmp;
                    }
                }
                else
                {
                    tmp->next->row = tmp->row-2;
                    tmp->next->column = tmp->column;
                }
            }
            tmp->next = new Bullet;
            tmp->next->row = tmp->row-2;
            tmp->next->column = tmp->column;
            Draw();
            tmp->next->PrintBlow();
        }
        //controllo se è stato premuto un tasto
        int key = getch();
        if (key != ERR)
        {
            //mvprintw(row,column,"Sono fermo");
            //nodelay (stdscr, false);
            //getch();
            //nodelay (stdscr, true);
            Move(key);
            Bullet *tmp;
            for (tmp = missile->first; tmp->next!=NULL; tmp = tmp->next);
            Shot(tmp->next);
        }
    }

}

//Distruttore
Spacecraft::~Spacecraft()
{
    return;
}
