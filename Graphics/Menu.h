#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "../Globals.h"
#include "Window.h"

class Menu
{
    //Dichiaro le coordinate per i menu
    int startx;
    int starty;

    int highlight;  //Variabile per le voci del menu
    int choice;     //Scelta dell'utente
    int menu_type;  //Per il tipo di menu

    //Dichiaro un array di stringhe per le scelte dell'utente
    const char* first_menu_choices[N_CHOICES] = {"Nuova partita","Partita precedente","Guida","Esci"};

    //Dichiaro un array di stringhe per le scelte dell'utente
    const char* secondary_menu_choices[N_CHOICES] = {"Riprendi","Riavvia","Menu Principale","Esci"};

    WINDOW *menu_win;           //Dichiaro un puntatore alla struttura WINDOW
    void PrintMenu(Window&);    //Dichiaro un metodo per la stampa del menu
    int SelectChoice(Window&);  //Dichiaro il metodo per gestire la scelta dell'utente

    public:

    //Costruttore e distruttore
    Menu(Window&);
    ~Menu();
    int GetChoice(); //Restituisce la scelta dell'utente
};

#endif // MENU_H_INCLUDED
