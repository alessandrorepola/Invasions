// Implementazione dei metodi della classe GameEntity

#include "GameEntity.h"

GameEntity::GameEntity()
{
    row = 0;
    column = 0;
    life = 0;
    direction = 0;
}


GameEntity::~GameEntity() {}

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
