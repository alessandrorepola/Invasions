#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "../Invasions.h"

class Menu
{
    //Dichiaro le coordinate per i menu
    int startx;
    int starty;

    //Variabile per le voci del menu
    int highlight;

    //Scelta dell'utente
    int choice;

    //Dichiaro un array di stringhe per le scelte dell'utente
    char* choices[N_CHOICES] = {"NUOVA PARTITA", "PARTITA PRECEDENTE", "GUIDA", "NOME GIOCATORE", "ESCI"};;

    //Dichiaro un puntatore alla struttura WINDOW
    WINDOW *menu_win;

    //Dichiaro un metodo per la stampa del menu
    void PrintMenu();

    public:

    //Costruttore e distruttore
    Menu();
    ~Menu();

    //Dichiaro il metodo per gestire la scelta dell'utente
    int SelectChoice();
};

#endif // MENU_H_INCLUDED
