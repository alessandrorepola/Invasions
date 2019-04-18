#include "spacecraft.h"

int main()
{
    initscr();              //Imposta la modalita curses
    resize_term(CONSOLE_HIGH, CONSOLE_LENGTH);  //Imposta le dimensioni della console
    curs_set (false);		//Rende il cursore invisibile
	keypad (stdscr, true);	//Abilita i tasti freccia
	noecho ();				//Disabilita l'echo dei tasti premuti
	nodelay (stdscr, true);	//Se non viene digitato alcun tasto la funzione getch() restituisce ERR
	Spacecraft player;      //Dichiaro un oggetto di tipo navicella per il giocatore
	Cannon c;               //Dichiaro un oggetto cannon per gestire i colpi

	//loop "infinito" della partita
	while (TRUE)
    {
        //Legge l'input da tastiera
        int key = getch();

        //Chiama la funzione per muovere la navicella e controlla se e' stato digitato q
        if (!player.Move(key))
            break;

        //Spara i colpi
        player.Shoot(c);
        player.Draw();
        refresh();
    }
    endwin(); //Termina la modalita' curses
    return 0;
}

