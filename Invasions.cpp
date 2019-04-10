#include "spacecraft.h"
#define CONSOLE_LENGTH 100
#define CONSOLE_HIGH 30

int main()
{
    initscr();              //imposta la modalita curses
    resize_term(CONSOLE_HIGH, CONSOLE_LENGTH);  //imposta le dimensioni della console
    curs_set (0);			//rende il cursore invisibile
	keypad (stdscr, true);	//attiva tasti extra (funzione e frecce)
	noecho ();				//non scrivere sulla console i tasti premuti
	raw ();					//l'input da tastiera non necessita di INVIO
	//nodelay (stdscr, true);	// getch() non aspetta che sia premuto un tasto.
	Spacecraft player;      //dichiaro un oggetto di tipo navicella per il giocatore
	Bullet *missile;        //dichiaro un puntatore ad una lista concatenata di oggetti Bullet
	//loop "infinito" della partita
	while (TRUE)
    {
        //missile = new Bullet; //dichiaro un oggetto sentinella per la lista di colpi
        int key = getch();
        if (player.Move(key)==EXIT)
        {
            break;
        }
        player.Shot(missile); //funzione per sparare che prende come argomento la sentinella della lista dei colpi
    }
    endwin(); //termina la funzionalita' curses
    return 0;
}

