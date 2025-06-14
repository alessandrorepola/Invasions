// Implementazione dei metodi della classe GameEntity

#include "GameEntity.h"

GameEntity::GameEntity(int row, int column, int life, int direction, Window *win):
    row(row),
    column(column),
    life(life),
    direction(direction),
    win(win)
{
    start = clock();
}


GameEntity::~GameEntity()
{
    win = nullptr;
}

int GameEntity::GetRow()
{
    return row;
}

int GameEntity::GetColumn()
{
    return column;
}

int GameEntity::GetLife()
{
    return life;
}

int GameEntity::GetDirection()
{
    return direction;
}

void GameEntity::DecreaseLife(int damage)
{
    life = life - damage;

    if (life < 0)
    {
        life = 0;
    }
}
