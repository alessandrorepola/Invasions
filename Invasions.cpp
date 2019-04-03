#include "spacecraft.h"
#include "blow.h"
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
	nodelay (stdscr, true);	//getch() non aspetta che sia premuto un tasto
	spacecraft allied;
	blow *bullet;
	//loop "infinito" della partita
	while (TRUE)
    {
        bullet = new blow[allied.row];
        int key = getch();
        if (allied.Move(key) == EXIT)
            break;
        for (int i=allied.row-1; i>0; i--)
        {
            bullet->Move(i,allied.column);
        }
    }
    endwin(); //termina la funzionalita' curses
    return 0;
}

