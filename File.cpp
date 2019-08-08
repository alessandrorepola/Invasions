/***********************************************
* File.cpp                                     *
* Implementazione dei metodi della classe File *
***********************************************/

#include "File.h"

#define FILE_BESTSCORE "BestScore.dat"
#define FILE_BULLET_LIST "Bullet.dat"
#define FILE_ENEMY_LIST "Enemy.dat"
#define FILE_OTHER_INFO "OtherInfo.dat"


//Controlla che sia gia' presente il file
bool File::Exists()
{
    f.open(FILE_BESTSCORE, std::ios::in);

    if (!f)
    {
        return false;
    }

    f.close();
    return true;
}

//Crea tutti i file
void File::Create()
{
    f.open(FILE_BESTSCORE);
    f.close();
    f.open(FILE_BULLET_LIST);
    f.close();
    f.open(FILE_ENEMY_LIST);
    f.close();
    f.open(FILE_OTHER_INFO);
    f.close();
}

void File::Save(int bestScore)
{
    f.open(FILE_BESTSCORE, std::ios::binary | std::ios::trunc | std::ios::out);
    f.write ((char*) &bestScore, sizeof(int));
    f.close();
}

void File::Restore(int& bestScore)
{
    f.open(FILE_BESTSCORE, std::ios::binary | std::ios::in);
    f.read ((char*) &bestScore, sizeof(int));
    f.close();
}

void File::Save(List *PlayerBulletList)
{
    f.open(FILE_BULLET_LIST, std::ios::binary | std::ios::trunc | std::ios::out);

    for(PlayerBulletList->SetIter(); !PlayerBulletList->EndList(); PlayerBulletList->SetNext())
    {
        f.write ((char*) PlayerBulletList->GetBullet(), sizeof(Bullet));
    }
    f.close();
}

void File::Save(Spacecraft player)
{
    f.open(FILE_OTHER_INFO, std::ios::binary | std::ios::trunc | std::ios::out);

    f.write ((char*) &player, sizeof(Spacecraft));

    f.close();
}

void File::Restore(List* PlayerBulletList)
{
    f.open(FILE_BULLET_LIST, std::ios::binary | std::ios::in);
    Bullet b;
    while (f.good())
    {
        f.read ((char*) &b, sizeof(Bullet));
        PlayerBulletList->Add(&b);
    }
    f.close();
/*
    f.open(FILE_ENEMY_LIST, std::ios::binary | std::ios::in);

    aliens->SetIter();

    while (f.good())
    {
        f.read ((char*) aliens, sizeof(Enemy));
        aliens->NextEnemy();
    }
    f.close();*/
}

void File::Restore(Spacecraft *player)
{
    f.open(FILE_OTHER_INFO, std::ios::binary | std::ios::in);

    f.read ((char*) player, sizeof(Spacecraft));

    f.close();
}
