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

class spacecraft
{
    int life;      //la vita della navicella

    public:

    int row;       //coordinata Y
    int column;    //coordinata X
    spacecraft();  //costruttore
    int Move(int); //sposta la navicella
    ~spacecraft(); //distruttore
};

#endif // SPACECRAFT_H_INCLUDED
