//File blow.h
#ifndef BLOW_H_INCLUDED
#define BLOW_H_INCLUDED

#include "spacecraft.h"
#define DELAY 1
#define DAMAGE 1

class blow
{
    int speed;
    int damage;

    public:

    blow();
    void Move(spacecraft);
    ~blow();
};

#endif // BLOW_H_INCLUDED
