/*********************************************************
* File.h                                                 *
* file contenete la classe File per la gestione dei file *
*********************************************************/

#ifndef FILEMANAGER_H_INCLUDED
#define FILEMANAGER_H_INCLUDED

#include "Globals.h"

class File
{
    std::fstream f;

    public:

    bool exists();
    bool create();
    int read();
    bool write();
};

#endif // FILEMANAGER_H_INCLUDED
