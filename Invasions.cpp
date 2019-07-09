
#include "Globals.h"
#include "Game.h"

int main()
{
    Globals::Init();
    Globals::Color();

    bool Restart = false;  //Per ricominciare senza ritornare al menu principale

    //Loop del gioco
    while(true)
    {
        //Oggetto game
        Game game;

        //Se l'utente ricomincia direttamente una nuova partita
        //Salta la schermata principale
        if (!Restart)
        {
            //Schermata principale
            game.MainScreen();
        }

        //loop "infinito" della partita
        Restart = game.StartGameLoop();
    }
    //endwin(); //Termina la modalita' curses
    return 0;
}
