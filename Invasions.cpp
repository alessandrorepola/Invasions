
#include "Globals.h"
#include "Game.h"

int main()
{
    Globals::Init();

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

        //loop della partita
        Restart = game.StartGameLoop();
    }
    return 0;
}
