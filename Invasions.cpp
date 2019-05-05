#include "Invasions.h"
#include "Game.h"

//Imposta le varie funzioni per ncurses
void SetConsole();

int main()
{
    initscr();     //Inizializzo la modalita' curses
    SetConsole();  //Imposto le funzioni per curses
    Game game;     //Dichiaro un oggetto game

    //Dichiaro una variabile per capire quando l'utente desidera uscire dalla partita
    bool endGame = FALSE;

	//loop "infinito" della partita
	while (!endGame)
    {
        //Sposta la nevicella del giocatore
        endGame = game.MoveSpacesraft();

        //Controlla se il colpo sparato dal nemico si e' mosso o il numico si e' spostato
        if (game.SpacecraftShoot() || game.MoveEnemy())
        {
            //Controlla se il nemico è stato colpito
            game.Hitted();
        }

        //Generazione dei nemici
        game.GenerationEnemy();

        //Aggiorno la schermata
        game.UpdateScreen();
    }
    endwin(); //Termina la modalita' curses
    return 0;
}

void SetConsole()
{
    resize_term(CONSOLE_HIGH, CONSOLE_LENGTH);  //Imposta le dimensioni della console
    curs_set (false);		//Rende il cursore invisibile
	keypad (stdscr, true);	//Abilita i tasti freccia
	noecho ();				//Disabilita l'echo dei tasti premuti
	srand(time(NULL));      //Per la generazione di valori random
	nodelay (stdscr, true);	//Se non viene digitato alcun tasto la funzione getch() restituisce ERR
}
