
#include "Globals.h"
#include "Game.h"

int main()
{
    Globals::Init();
    Globals::Color();

    bool endGame = true;  //Per uscire dal gioco

    //Loop del gioco
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
