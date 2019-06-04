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
        if (choice != RESTART)
        {
            Menu menu(FIRST_MENU); //Menu iniziale
            UserChoice(menu.GetChoice());
        }

        choice = EXIT;

        //loop "infinito" della partita
        while (true)
        {

            //Sposta la nevicella del giocatore
            switch (game.MoveSpacesraft())
            {
                case RESTART:
                    choice = RESTART;
                    break;

                case MAIN_MENU:
                    choice = MAIN_MENU;
                    break;

                case EXIT:
                    exit(INIT);
            }

            if (choice == RESTART || choice == MAIN_MENU)
            {
                break;
            }

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
    }
    while (choice != EXIT);
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

        case GUIDE:
            //TO DO
            break;

        case EXIT:
            exit(INIT);
    }
}

//Inizializzo le coppie di colori
void InitColor()
{
    init_color(COLOR_RED,1000,0,0);
    init_color(COLOR_BLUE,0,0,1000);
    init_color(COLOR_YELLOW,1000,1000,0);
    init_color(COLOR_GREEN,0,1000,0);
    init_color(ORANGE,1000,500,0);
    init_color(COLOR_CYAN,0,1000,1000);
    init_color(COLOR_MAGENTA, 1000, 0, 1000);
    init_color(COLOR_WHITE, 1000, 1000, 1000);
}

//Inizializzo le coppie di colori
void ColorPair()
{
    //Controllo che il terminale supporti i colori
    if (has_colors())
    {
        if (can_change_color())
        {
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
