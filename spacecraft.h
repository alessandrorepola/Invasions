//File spacecraft.h
#ifndef SPACECRAFT_H_INCLUDED
#define SPACECRAFT_H_INCLUDED

#ifdef WIN32
    #include <curses.h>
#else
    #include <ncurses.h>
#endif

#define LIFE 3
#define EXIT 0
#define MOVE 1
#define SHOT 2

class spacecraft
{
    friend class blow;

    int row;       //coordinata Y
    int column;    //coordinata X
    int life;      //la vita della navicella

    public:

    spacecraft();  //costruttore
    int Move(int); //sposta la navicella
    void shot();   //spara i colpi
    ~spacecraft(); //distruttore
};

#endif // SPACECRAFT_H_INCLUDED
