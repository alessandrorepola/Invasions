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
    f.open(FILE_BESTSCORE, std::ios::binary);

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

void File::WriteBestScore(int bestScore)
{
    f.open(FILE_BESTSCORE, std::ios::binary | std::ios::trunc | std::ios::out);
    f.write ((char*) &bestScore, sizeof(int));
    f.close();
}

int File::ReadBestScore()
{
    int bestScore;
    f.open(FILE_BESTSCORE, std::ios::binary | std::ios::in);
    f.read ((char*) &bestScore, sizeof(int));
    f.close();
    return bestScore;
}

void File::WriteObj(Cannon c, Mothership aliens)
{
   /* f.open(FILE_BULLET_LIST, std::ios::binary | std::ios::trunc | std::ios::out);

    for(c.SetIter(); c.GetIter()!= NULL; c.NextBullet())
    {
        sizeCannon = sizeCannon + sizeof(Bullet);

    }
    f.close();*/

    /*f.open(FILE_ENEMY_LIST, std::ios::binary | std::ios::trunc | std::ios::out);

    for(aliens.SetIter(); aliens.GetIter()!= NULL; aliens.NextEnemy())
    {
        f.write ((char*) &aliens, sizeof(aliens));
    }
    f.close();*/
}

void File::WriteOtherInfo(Spacecraft player, int score)
{
    f.open(FILE_OTHER_INFO, std::ios::binary | std::ios::trunc | std::ios::out);

    f.write ((char*) &player, sizeof(Spacecraft));
    f.write ((char*) &score, sizeof(int));

    f.close();
}

void File::ReadObj(Cannon *c, Mothership *aliens)
{
    f.open(FILE_BULLET_LIST, std::ios::binary | std::ios::in);
    //c->SetIter();

    //while (f.good())
    {
        int sizeCannon;
        f.read ((char*) &sizeCannon, sizeof(int));
        f.read ((char*) c, sizeCannon);
        //c->NextBullet();
    }
    f.close();

   /* f.open(FILE_ENEMY_LIST, std::ios::binary | std::ios::in);

    aliens->SetIter();

    while (f.good())
    {
        f.read ((char*) aliens, sizeof(Enemy));
        aliens->NextEnemy();
    }
    f.close();*/
}

void File::ReadOtherInfo(Spacecraft *player, int *score)
{
    f.open(FILE_OTHER_INFO, std::ios::binary | std::ios::in);

    f.read ((char*) player, sizeof(Spacecraft));
    f.read ((char*) score, sizeof(int));

    f.close();
}
