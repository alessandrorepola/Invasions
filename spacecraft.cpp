//File spacecraft.cpp
#include "spacecraft.h"

//Costruttore
Spacecraft::Spacecraft()
{
    //Vita iniziale della navicella
    life = SPACECRAFT_LIFE;

    //Coordinate iniziali della navicella
    row = CONSOLE_HIGH/2;
    column = CONSOLE_LENGTH/2;
}

//Restituisce la riga della navicella
int Spacecraft::GetRow()
{
    return row;
}

//Restituisce la colonna della navicella
int Spacecraft::GetColumn()
{
    return column;
}

//Movimeto della navicella
bool Spacecraft::Move(int key)
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
            return false;

        // Se non viene premuto nessun tasto o un altro tasto diverso dai precedenti ritorana al loop principale
        case ERR:
        default:
            return true;
    }
    CheckMove();
    return true;
}

void Spacecraft::CheckMove()
{
	if (column <= INIT+2)
	{
		column = INIT+2;
	}
	if (row <= INIT)
	{
		row = INIT;
	}
	if (column >= CONSOLE_LENGTH)
	{
		column = CONSOLE_LENGTH;
	}
	if (row >= CONSOLE_HIGH)
	{
		row = CONSOLE_HIGH-1;
	}
}

//Disegna la navicella
void Spacecraft::Draw ()
{
    mvprintw(row,column-2,"\\-^-/");
}

//Spara il colpo
void Spacecraft::Shoot(Cannon &c)
{
    c.AddObject(row-1, column);
    c.MoveObject();
}

//Decremanta la vita della navicella
bool Spacecraft::DecreseLife(int damage)
{
    life = life-damage;

    //Controllo se la navicella è stata distrutta
    if (life <= INIT)
    {
        return true;
    }
    return false;
}

//Distruttore
Spacecraft::~Spacecraft()
{

}
