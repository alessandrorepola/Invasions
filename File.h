/*********************************************************
* File.h                                                 *
* file contenete la classe File per la gestione dei file *
*********************************************************/

#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include "Spacecraft.h"
#include <iostream>
#include <fstream>

class File
{
    std::fstream f;

    public:

    bool Exists();
    void Create();
    void Restore(int&);
    void Restore(List*);
    void Restore(Spacecraft*);
    void Save(int);
    void Save(List*);
    void Save(Spacecraft);
};

#endif // FILE_H_INCLUDED
