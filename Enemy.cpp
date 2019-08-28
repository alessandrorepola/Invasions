//File Enemy.cpp

#include "Enemy.h"
#include "Bullet.h"


Enemy::Enemy(Window *win):
    GameEntity(int(), int(), ENEMY_LIFE, int(), win),
    lastBulletTime(clock()),
    bulletDirection(SOUTH),
    bulletGenerationTime(TIME_ENEMY_BULLET),
    generationTime(ENEMY_GENERATION_TIME)
{
    //Genera il lato da cui parte il nemico
    side = rand()%CONSOLE_SIDE;

    //Posiziono il nemico
    CoordGeneration();
}

//Genera le posizioni iniziali del nemico
void Enemy::CoordGeneration()
{
    switch (side)
    {
        case UP:
            row = win->GetY();
            column = (rand()%(win->GetWidth()-4))+2;
            break;

        case DOWN:
            row = win->GetHeight()-2;
            column = (rand()%(win->GetWidth()-4))+2;
            break;

        case LEFT:
            column = win->GetX()+1;
            row = (rand()%(win->GetHeight()-2))+1;
            break;

        case RIGHT:
            column = win->GetWidth()-3;
            row = (rand()%(win->GetHeight()-2))+1;
            break;
    }
}

//Per il movimento del nemico
void Enemy::Move()
{
    clock_t time;
    double diff = INIT;

    //Controllo il tempo trascorso dall'ultimo controllo
    time = clock();
    diff = (double)(time-start);
    diff = diff/CLOCKS_PER_SEC;

    //Controllo se si può muovere
    if (diff >= ENEMY_SPEED)
    {
        start = time;

        //Imposta una direzione in cui si puo' spostare il nemico
        SetDirection();

        //Sposta il nemico di una posizione in base alla direzione
        SetMovement();
    }
}

//Imposta una direzione in cui si puo' spostare la navicella
void Enemy::SetDirection()
{
    //Controllo se il nemico si trova lungo il bordo superiore della console
    if (row <= win->GetY())
    {
        //Controllo se si trova nell'angolo in alto a sinistra
        if (column <= win->GetX()+1)
        {
            //Genero una direzione in cui puo' muoversi il nemico
            while ((direction != EST) && (direction != SOUTH) && (direction != SOUTH_EST))
                direction = rand()%SOUTH_EST+1;
        }

        //Altrimenti se si trova nell'angolo in alto a destra
        else if (column >= win->GetWidth()-3)
        {
            //Genero una direzione in cui puo' muouersi il nemico
            while ((direction != WEST) && (direction != SOUTH) && (direction != SOUTH_WEST))
                direction = rand()%SOUTH_WEST;
        }

        //Altrimenti
        else
        {
            while ((direction != EST) && (direction != WEST) && (direction != SOUTH_EST) && (direction != SOUTH_WEST) && (direction != SOUTH))
                direction = rand()%SOUTH_WEST;
        }
    }

    //Controllo se il nemico si trova lungo il bordo inferiore della console
    else if (row >= win->GetHeight()-2)
    {
        //Controllo se si trova nell'angolo in basso a sinistra
        if (column <= win->GetX()+1)
        {
            while ((direction != NORTH) && (direction != NORTH_EST))
                direction = rand()%NORTH_WEST;
        }

        //Altrimenti se si trova nell'angolo in basso a destra
        else if (column >= win->GetWidth()-3)
        {
            while ((direction != NORTH) && (direction != NORTH_WEST))
                direction = rand()%SOUTH_WEST;
        }

        //Altrimenti
        else
        {
            while ((direction != NORTH_EST) && (direction != NORTH_WEST) && /*(direction != WEST) && (direction != EST) && */(direction != NORTH))
                direction = rand()%SOUTH_WEST;
        }
    }

    //Controllo se il nemico si trova sul lato sinistro della console
    else if (column <= win->GetX()+1)
    {
        //Non ricontrollo nuovamente se il nemico è negli angoli in quanto già è stato verificato precedentemente
        while ((direction != NORTH) && (direction != SOUTH) && (direction != EST) && (direction != NORTH_EST) && (direction != SOUTH_EST))
            direction = rand()%SOUTH_WEST;
    }

    //Controllo se il nemico si trova sul lato destro della console
    else if (column >= win->GetWidth()-3)
    {
        while ((direction != NORTH) && (direction != SOUTH) && (direction != WEST) && (direction != NORTH_WEST) && (direction != SOUTH_WEST))
            direction = rand()%SOUTH_WEST;
    }
}

//Spostamento del nemico
void Enemy::SetMovement()
{
    switch (direction)
    {
        case NORTH:
            --row;
            break;

        case SOUTH:
            ++row;
            break;

        case EST:
            ++column;
            break;

        case WEST:
            --column;
            break;

        case NORTH_EST:
            --row;
            ++column;
            break;

        case NORTH_WEST:
            --row;
            --column;
            break;

        case SOUTH_EST:
            ++row;
            ++column;
            break;

        case SOUTH_WEST:
            ++row;
            --column;
            break;
    }
}

//Disegna i nemici
void Enemy::Draw ()
{
    wattron(win->GetWin(), COLOR_PAIR(GREEN));
    mvwprintw(win->GetWin(), row, column-1 ,"\\0/");
    wattroff(win->GetWin(), COLOR_PAIR(GREEN));
}

//Sparo del nemico
void Enemy::Shoot(List &EnemyBulletList)
{
    clock_t time;
    double diff = INIT;

    //Controllo il tempo trascorso dall'ultimo colpo
    time = clock();
    diff = (double)(time-lastBulletTime);
    diff = diff/CLOCKS_PER_SEC;

    //Controllo se si può muovere
    if (diff >= bulletGenerationTime)
    {
        lastBulletTime = time;
        Bullet *bulletp = new Bullet(GetRow()+1, GetColumn(), bulletDirection, win);
        EnemyBulletList.Add(bulletp, 0);
    }

}

//Decrementa la vita del nemico
bool Enemy::CheckDie()
{
    life = life - BULLET_DAMAGE;

    //Controllo se il nemico è stato distrutto
    if(life <= INIT)
    {
        return true;
    }

    return false;

}

double Enemy::GetGenerationTime()
{
    return generationTime;
}

//Distruttore
Enemy::~Enemy()
{

}
