//File spacecraft.cpp
#include "Spacecraft.h"

//Costruttore
Spacecraft::Spacecraft()
{
    //Vita iniziale della navicella
    life = SPACECRAFT_LIFE;

    //Coordinate iniziali della navicella
    row = GAME_WIN_HIGH/2;
    column = GAME_WIN_LENGTH/2;
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
int Spacecraft::Move(int key, Window &parent)
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

        case 'p':
        case 'P':
        {
            Menu secondary_menu(parent);
            return secondary_menu.GetChoice();
        }

        // Se non viene premuto nessun tasto o un altro tasto diverso dai precedenti ritorana al loop principale
        case ERR:
        default:
            break;
    }
    CheckMove();
    return 0;
}

//Per controllare che la navicella del giocatore finisca fuori dal campo da gioco
void Spacecraft::CheckMove()
{
	if (column <= START_XY+2)
	{
		column = START_XY+2;
	}
	if (row <= START_XY)
	{
		row = START_XY;
	}
	if (column >= GAME_WIN_LENGTH-3)
	{
		column = GAME_WIN_LENGTH-3;
	}
	if (row >= GAME_WIN_HIGH)
	{
		row = GAME_WIN_HIGH-1;
	}
}

//Disegna la navicella
void Spacecraft::Draw (WINDOW *win)
{
    wattrset(win, COLOR_PAIR(YELLOW));
    mvwprintw(win,row,column-2,"\\-^-/");
    wattrset(win, COLOR_PAIR(WHITE));
    wrefresh(win);
}

//Spara il colpo
void Spacecraft::Shoot(Cannon &c)
{
    c.AddObject(row-1, column, PLAYER);
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

//Restituisce il valore della vita
int Spacecraft::GetLife()
{
    return life;
}

//Distruttore
Spacecraft::~Spacecraft()
{

}
