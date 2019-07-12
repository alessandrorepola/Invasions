// Implementazione dei metodi della classe GameEntity

#include "GameEntity.h"

GameEntity::GameEntity()
{
    row = 0;
    column = 0;
    life = 0;
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
