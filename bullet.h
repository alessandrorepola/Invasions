//File bullet.h
#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED
#ifdef WIN32
    #include <curses.h>
#else
    #include <ncurses.h>
#endif
#define DELAY 1
#define DAMAGE 1

class Bullet
{
    friend class Spacecraft;

    int speed;        //Velocità del colpo
    int damage;       //Danno del colpo
    int row;          //Riga del colpo
    int column;       //Colonna del colpo
    Bullet *first;    //Punta al primo colpo in testa
    Bullet *next;     //Puntatore al colpo successivo
    Bullet *prev;     //Puntatore al colpo precedente
    void PrintBlow(); //Stampa il colpo

    public:

    Bullet();           //Costruttore
    int Move();       //Muove il colpo sparato
    ~Bullet();          //Distruttore
};

#endif // BULLET_H_INCLUDED
