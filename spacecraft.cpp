//File spacecraft.cpp
#include "Spacecraft.h"

//Costruttore
Spacecraft::Spacecraft(Window *win):
    GameEntity(win->GetHeight()/2, win->GetWidth()/2, SPACECRAFT_LIFE, int(), win),
    bulletDirection(NORTH),
    bulletGenerationTime(TIME_PLAYER_BULLET)
{}

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
    //Per controllare che la navicella del giocatore finisca fuori dal campo da gioco
    if (column <= win->GetX()+2)
	{
		column = win->GetX()+2;
	}
	if (row <= win->GetY())
	{
		row = win->GetY();
	}
	if (column >= win->GetWidth()-4)
	{
		column = win->GetWidth()-4;
	}
	if (row >= win->GetHeight()-1)
	{
		row = win->GetHeight()-2;
	}
}

//Disegna la navicella
void Spacecraft::Draw ()
{
    wattrset(win->GetWin(), COLOR_PAIR(YELLOW));
    mvwprintw(win->GetWin(),row,column-2,"\\-^-/");
    wattrset(win->GetWin(), COLOR_PAIR(WHITE));
}

//Spara il colpo
void Spacecraft::Shoot(List &PlayerBulletList)
{
    Bullet *pbullet = new Bullet(GetRow()-1, GetColumn(), bulletDirection, win);
    PlayerBulletList.Add(pbullet, bulletGenerationTime);

    for(PlayerBulletList.SetIter(); !PlayerBulletList.EndList(); PlayerBulletList.SetNext())
    {
        PlayerBulletList.GetBullet()->Move();

        //Controlla se ci sono colpi da cancellare
        if (PlayerBulletList.GetBullet()->Remove())
        {
            PlayerBulletList.Remove(PlayerBulletList.GetBullet());
        }
    }
}

//Distruttore
Spacecraft::~Spacecraft()
{

}
