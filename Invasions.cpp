
#include "Invasions.h"
#include "Game.h"
#include "Graphics/Menu.h"

//Imposta le varie funzioni per ncurses
void SetConsole();

//Per decidere cosa fare in base alla scelta della'utente
void UserChoice(int, Window&);

//Imposta le dimensioni del terminale
void SizeTerm();

//Inizializza le tonalità di colore
void InitColor();

//Inizializzo le coppie di colori
void ColorPair();

//Stampa a video l'help
void Help(Window&);

int main()
{
    initscr();     //Inizializzo la modalita' curses
    start_color(); //Per utilizzare i colori
    InitColor();   //Inizializzo le tonalità di colore
    ColorPair();   //Inizializzo le coppie di colori
    SetConsole();  //Imposto le funzioni per curses
    bool endGame = true;  //Per uscire dal gioco
    do
    {
        //Oggetto game
        Game game;

        //Se l'utente ricomincia direttamente una nuova partita
        //Salta la fase della schermata principale
        if (endGame)
        {
            //Schermata principale
            game.MainScreen();
        }

        //loop "infinito" della partita
        endGame = game.StartGameLoop();
    }
    while (!endGame);  //Finchè l'utente non decide di uscire dal gioco
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
    resize_term(WIN_HEIGHT+START_XY, WIN_WIDTH+START_XY);
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
void Help(Window &parent)
{
    Window help(parent.GetWin(), parent.GetWidth()/4, parent.GetHeight()/4, parent.GetWidth()/2, parent.GetHeight()/2);
    werase(parent.GetWin());
    wattrset(help.GetWin(), COLOR_PAIR(CYAN));
    wprintw(help.GetWin(), "\n                  Comandi di gioco\n");
    wprintw(help.GetWin(), "\n      Comando                     Tasto\n");
    wattrset(help.GetWin(), COLOR_PAIR(WHITE));
    wprintw(help.GetWin(), "\n      Sopra:                        "); waddch(help.GetWin(),ACS_UARROW);
    wprintw(help.GetWin(), "\n      Sotto:                        "); waddch(help.GetWin(),ACS_DARROW);
    wprintw(help.GetWin(), "\n      Destra:                       "); waddch(help.GetWin(),ACS_RARROW);
    wprintw(help.GetWin(), "\n      Sinistra:                     "); waddch(help.GetWin(),ACS_LARROW);
    wprintw(help.GetWin(), "\n      Pausa:                        p");
    wprintw(help.GetWin(), "\n      Esci:                         q");
    wattrset(help.GetWin(), COLOR_PAIR(CYAN));
    wprintw(help.GetWin(), "\n\n                  Comandi del menu\n");
    wattrset(help.GetWin(), COLOR_PAIR(WHITE));
    wprintw(help.GetWin(), "\n      Voce Precedente:              "); waddch(help.GetWin(),ACS_UARROW);
    wprintw(help.GetWin(), "\n      Voce Successiva:              "); waddch(help.GetWin(),ACS_DARROW);
    wprintw(help.GetWin(), "\n      Scegli:                     Enter");

    help.PrintWinBorder();
    parent.PrintWinBorder();
    wattrset(parent.GetWin(), COLOR_PAIR(BLUE));
    mvwprintw(parent.GetWin(), 9, 30, " GUIDA ");
    wattrset(parent.GetWin(), COLOR_PAIR(WHITE));
    wrefresh(parent.GetWin());
    getchar();
}
