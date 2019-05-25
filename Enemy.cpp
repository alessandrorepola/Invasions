//File Enemy.cpp
#include "Enemy.h"

Enemy::Enemy()
{
    next = NULL;
    prev = NULL;
    life = ENEMY_LIFE;

    //Genera il lato da cui parte il nemico
    side = rand()%CONSOLE_SIDE;

    //Posiziono il nemico
    CoordGeneration();

    //Calcolo il tempo dall'inizio del gioco alla generazione del nemico
    start = clock();
}

//Genera le posizioni iniziali del nemico
void Enemy::CoordGeneration()
{
    switch (side)
    {
        case UP:
            row = START_XY;
            column = (rand()%(CONSOLE_LENGTH-4))+2;
            break;

        case DOWN:
            row = CONSOLE_HIGH-1;
            column = (rand()%(CONSOLE_LENGTH-4))+2;
            break;

        case LEFT:
            column = START_XY+1;
            row = (rand()%(CONSOLE_HIGH-2))+1;
            break;

        case RIGHT:
            column = CONSOLE_LENGTH-2;
            row = (rand()%(CONSOLE_HIGH-2))+1;
            break;
    }
}

//Per il movimento del nemico
void Enemy::Move()
{
    clock_t time;
    double diff = INIT;

    //Controllo se ci sono altri nemici
    if (next != NULL)
        next->Move();

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
        Movement();
    }
}

//Imposta una direzione in cui si puo' spostare la navicella
void Enemy::SetDirection()
{
    //Controllo se il nemico si trova lungo il bordo superiore della console
    if (row <= START_XY)
    {
        //Controllo se si trova nell'angolo in alto a sinistra
        if (column <= START_XY+1)
        {
            //Genero una direzione in cui puo' muoversi il nemico
            while ((direction != EST) && (direction != SOUTH) && (direction != SOUTH_EST))
                direction = rand()%SOUTH_EST+1;
        }

        //Altrimenti se si trova nell'angolo in alto a destra
        else if (column >= CONSOLE_LENGTH-2)
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
    else if (row >= CONSOLE_HIGH-1)
    {
        //Controllo se si trova nell'angolo in basso a sinistra
        if (column <= START_XY+1)
        {
            while ((direction != NORTH) && (direction != NORTH_EST))
                direction = rand()%NORTH_WEST;
        }

        //Altrimenti se si trova nell'angolo in basso a destra
        else if (column >= CONSOLE_LENGTH-2)
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
    else if (column <= START_XY+1)
    {
        //Non ricontrollo nuovamente se il nemico è negli angoli in quanto già è stato verificato precedentemente
        while ((direction != NORTH) && (direction != SOUTH) && (direction != EST) && (direction != NORTH_EST) && (direction != SOUTH_EST))
            direction = rand()%SOUTH_WEST;
    }

    //Controllo se il nemico si trova sul lato destro della console
    else if (column >= CONSOLE_LENGTH-2)
    {
        while ((direction != NORTH) && (direction != SOUTH) && (direction != WEST) && (direction != NORTH_WEST) && (direction != SOUTH_WEST))
            direction = rand()%SOUTH_WEST;
    }
}

//Spostamento del nemico
void Enemy::Movement()
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

//Restituisce la riga del nemico
int Enemy::GetRow()
{
    return row;
}

//Restituisce la colonna del nemico
int Enemy::GetColumn()
{
    return column;
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

//Distruttore
Enemy::~Enemy()
{

}
