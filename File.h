/*********************************************************
* File.h                                                 *
* file contenete la classe File per la gestione dei file *
*********************************************************/

#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include "Cannon.h"
#include "Mothership.h"
#include "Spacecraft.h"
#include <iostream>
#include <fstream>

class File
{
    std::fstream f;

    public:

    bool Exists();
    void Create();
    int ReadBestScore();
    void ReadObj(Cannon*, Mothership*);
    void ReadOtherInfo(Spacecraft*, int*);
    void WriteBestScore(int);
    void WriteObj(Cannon, Mothership);
    void WriteOtherInfo(Spacecraft, int);
};

#endif // FILE_H_INCLUDED
