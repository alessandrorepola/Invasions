//File spacecraft.cpp
#include "Spacecraft.h"

//Costruttore
Spacecraft::Spacecraft()
{
    //Vita iniziale della navicella
    life = SPACECRAFT_LIFE;

    //Coordinate iniziali della navicella
    row = GAME_WIN_HEIGHT/2;
    column = GAME_WIN_WIDTH/2;
}

//Decrementa la colonna
void Spacecraft::DecreaseColumn()
{
    --column;
}

//Decrementa la riga
void Spacecraft::DecreaseRow()
{
    --row;
}

//Incremanta la colonna
void Spacecraft::IncreaseColumn()
{
    ++column;
}

//Incrementa la riga
void Spacecraft::IncreaseRow()
{
    ++row;
}

//Movimeto della navicella
void Spacecraft::Move()
{
    CheckMove();
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
	if (column >= GAME_WIN_WIDTH-3)
	{
		column = GAME_WIN_WIDTH-3;
	}
	if (row >= GAME_WIN_HEIGHT)
	{
		row = GAME_WIN_HEIGHT-1;
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
void Spacecraft::Shoot(List &BulletList)
{
    BulletList.Add(row-1, column, PLAYER);
    BulletList.Move();
}

//Decremanta la vita della navicella
bool Spacecraft::DecreaseLife(int damage)
{
    life = life-damage;

    //Controllo se la navicella è stata distrutta
    if (life <= 0)
    {
        life = 0;
        return true;
    }
    return false;
}

//Distruttore
Spacecraft::~Spacecraft()
{

}
