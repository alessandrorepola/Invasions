#include "Invasions.h"
#include "Game.h"
#include "Graphics/Menu.h"

//Imposta le varie funzioni per ncurses
void SetConsole();

//Per decidere cosa fare in base alla scelta della'utente
void UserChoice(int);

//Imposta le dimensioni del terminale
void SizeTerm();

//Inizializza le tonalità di colore
void InitColor();

//Inizializzo le coppie di colori
void ColorPair();

//Stampa a video l'help
void Help();

int main()
{
    initscr();     //Inizializzo la modalita' curses
    start_color(); //Per utilizzare i colori
    InitColor();   //Inizializzo le tonalità di colore
    ColorPair();   //Inizializzo le coppie di colori
    SetConsole();  //Imposto le funzioni per curses
    int choice;    //Per la scelta dell'utente nel caso dovesse mettere in pausa
    do
    {
        Game game;     //Dichiaro un oggetto game

        //Se l'utente decide di riavviare la partita salta la fase di scelta del menu principale
        if (choice != RESTART)
        {
            Menu menu(game.GetMainWin()); //Menu iniziale
            UserChoice(menu.GetChoice()); //Controllo la scelta dell'utente relativo al menu iniziale
        }

        //Reimposto la variabile choice per evitare un loop sulla schermata principale
        choice = EXIT;

        //loop "infinito" della partita
        choice = game.StartGameLoop();
    }
    while (choice != EXIT);  //Finchè l'utente non decide di uscire dal gioco
    endwin(); //Termina la modalita' curses
    return 0;
}

void SetConsole()
{
    SizeTerm();             //Imposta le dimensioni della console
    curs_set (false);		//Rende il cursore invisibile
	keypad (stdscr, true);	//Abilita i tasti freccia
	noecho ();				//Disabilita l'echo dei tasti premuti
	srand(time(NULL));      //Per la generazione di valori random
	nodelay (stdscr, true);	//Se non viene digitato alcun tasto la funzione getch() restituisce ERR
}

//Ridimensiona il terminale
void SizeTerm()
{
    resize_term(WIN_HIGH+START_XY, WIN_LENGTH+START_XY);
}

//Per la scelta dell'utente
void UserChoice(int choice)
{
    switch(choice)
    {
        case NEW_MATCH:
            break;

        case LAST_MATCH:
            //TO DO
            break;

        case HELP:
            Help();
            break;

        case EXIT:
            exit(INIT);
    }
}

//Inizializzo le coppie di colori
void InitColor()
{
    init_color (COLOR_RED,     FULL_COLOR,  EMPTY_COLOR,  EMPTY_COLOR);
    init_color (COLOR_BLUE,    EMPTY_COLOR, EMPTY_COLOR,  FULL_COLOR);
    init_color (COLOR_YELLOW,  FULL_COLOR,  FULL_COLOR,   EMPTY_COLOR);
    init_color (COLOR_GREEN,   EMPTY_COLOR, FULL_COLOR,   EMPTY_COLOR);
    init_color (ORANGE,        FULL_COLOR,  MEDIUM_COLOR, EMPTY_COLOR);
    init_color (COLOR_CYAN,    EMPTY_COLOR, FULL_COLOR,   FULL_COLOR);
    init_color (COLOR_MAGENTA, FULL_COLOR,  EMPTY_COLOR,  EMPTY_COLOR);
    init_color (COLOR_WHITE,   FULL_COLOR,  FULL_COLOR,   FULL_COLOR);
}

//Inizializzo le coppie di colori
void ColorPair()
{
    //Controllo che il terminale supporti i colori
    if (has_colors())
    {
        //Controllo che il terminale consenta di cambiare i colori di default
        if (can_change_color())
        {
            //Inizializzo i colori
            init_pair(RED,      COLOR_RED,     COLOR_BLACK);
            init_pair(YELLOW,   COLOR_YELLOW,  COLOR_BLACK);
            init_pair(BLUE,     COLOR_BLUE,    COLOR_BLACK);
            init_pair(ORANGE,   ORANGE,        COLOR_BLACK);
            init_pair(CYAN,     COLOR_CYAN,    COLOR_BLACK);
            init_pair(GREEN,    COLOR_GREEN,   COLOR_BLACK);
            init_pair(MAGENTA,  COLOR_MAGENTA, COLOR_BLACK);
            init_pair(WHITE,    COLOR_WHITE,   COLOR_BLACK);
        }
    }
}

//Stampa a video l'Help
void Help()
{
    Window help_win; //Dichiaro una finestra per la guida
}
