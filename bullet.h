//File bullet.h
#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED
#include <ctime>
#ifdef WIN32
    #include <curses.h>
#else
    #include <ncurses.h>
#endif
#define DELAY 1
#define DAMAGE 1

class Bullet
{
    friend class Cannon;

    int speed;        //Velocità del colpo
    int damage;       //Danno del colpo
    int row;          //Riga del colpo
    int column;       //Colonna del colpo
    Bullet *next;     //Puntatore al colpo successivo
    Bullet *prev;     //Puntatore al colpo precedente
    clock_t start;    //Misura il tempo da quando è stato sparato il colpo

    public:

    Bullet();          //Costruttore
    Bullet(int, int);  //Prende come argomento la riga e la colonna
    void Move();       //Muove il colpo sparato
    ~Bullet();         //Distruttore
};

#endif // BULLET_H_INCLUDED
