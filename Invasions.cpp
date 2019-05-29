#include "Invasions.h"
#include "Game.h"
#include "Graphics/Menu.h"

//Fare la stampa all'interno della console

//Imposta le varie funzioni per ncurses
void SetConsole();

//Per decidere cosa fare in base alla scelta della'utente
void UserChoice(int);

int main()
{
    initscr();     //Inizializzo la modalita' curses
    SetConsole();  //Imposto le funzioni per curses
    Game game;     //Dichiaro un oggetto game
    Menu menu(FIRST_MENU); //Menu iniziale
    UserChoice(menu.GetChoice());

    //Dichiaro una variabile per capire quando l'utente desidera uscire dalla partita
    bool endGame = FALSE;

	//loop "infinito" della partita
	while (!endGame)
    {

        //Sposta la nevicella del giocatore
        endGame = game.MoveSpacesraft();

        //Sparo del giocatore
        game.SpacecraftShoot();

        //Sparo del nemico
        game.EnemyShoot();

        //Sposta gli alieni
        game.MoveEnemy();

        //Controlla se il nemico è stato colpito
        game.EnemyHitted();

        //Controlla se il nemico è stato colpito
        game.PlayerHitted();

        //Generazione dei nemici
        game.GenerationEnemy();

        //Aggiorno la schermata
        game.UpdateScreen();

        //Contrlla se c'è stata una collisione tra ilo nemico e la navicella
        game.Collision();
    }
    endwin(); //Termina la modalita' curses
    return 0;
}

void SetConsole()
{
      //Imposta le dimensioni della console
    curs_set (false);		//Rende il cursore invisibile
	keypad (stdscr, true);	//Abilita i tasti freccia
	noecho ();				//Disabilita l'echo dei tasti premuti
	srand(time(NULL));      //Per la generazione di valori random
	nodelay (stdscr, true);	//Se non viene digitato alcun tasto la funzione getch() restituisce ERR
}

//Ridimensiona il terminale
void SizeTerm()
{
    #ifdef WIN 32
        resize_term(WIN_HIGH+START_XY, WIN_LENGTH+START_XY);
    #endif
}

//Per la scelta dell'utente
void UserChoice(int choice)
{
    switch(choice)
    {
        case NEW_MATCH:
            return ;

        case LAST_MATCH:
            //TO DO
            break;

        case GUIDE:
            //TO DO
            break;

        case EXIT:
            exit(INIT);
    }
}
