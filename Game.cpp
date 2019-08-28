/**********************************************************
* Game.cpp                                                *
* Contiene l'implementazione dei metodi della classe Game *
**********************************************************/

#include "Game.h"
#include "Widgets.h"

//Costruttore
Game::Game():
    score(INIT),
    bonus(nullptr)
{
    //Ripristino il moiglior punteggio salvato
    SetBestScore();

    //Finestra di gioco
    game_win = new Window(main_win.GetWin(), main_win.GetX(), main_win.GetY(), main_win.GetWidth()-(main_win.GetWidth()/6), main_win.GetHeight());

    //Finestra per la visualizzazione del punteggio
    info_win = new Window(main_win.GetWin(), game_win->GetWidth()+1, main_win.GetY(), main_win.GetWidth()/6, main_win.GetHeight());

    //Oggetto navicella giocatore
    player = new Spacecraft(game_win);
}

//Per la scelta dell'utente
void Game::UserChoice(int choice)
{
    switch(choice)
    {
        case NEW_MATCH:
            break;

        case LAST_MATCH:
            ResumeLastMatch();
            break;

        case HELP:
            Widgets::Help(GetMainWin());
            MainScreen();
            break;

        case EXIT:
            PlayerBulletList.DeleteList();
            EnemyList.DeleteList();
            endwin();
            exit(INIT);
    }
}

//Schermata principale
void Game::MainScreen()
{
    werase(main_win.GetWin());

    //Disegno la finestra principale
    main_win.PrintWinBorder();
    Widgets::Banner(main_win.GetWin());
    wrefresh(main_win.GetWin());

    //Messaggio iniziale
    Widgets::StartMessage(main_win.GetWin());

    //Menu principale
    Menu mainMenu(GetMainWin());
    werase(main_win.GetWin());
    UserChoice(mainMenu.GetChoice());
}

//Loop principale del gioco
bool Game::StartGameLoop()
{
    while (true)
    {
        //Analizza l'input utente
        switch (UserInput())
        {
            case RESTART:
                return true;

            case MAIN_MENU:
                SaveBestScore();
                SaveGameStatus();
                PlayerBulletList.DeleteList();
                EnemyList.DeleteList();
                return false;

            case EXIT:
                SaveBestScore();
                SaveGameStatus();
                PlayerBulletList.DeleteList();
                EnemyList.DeleteList();
                Globals::End();
        }

        //Sposta la navicella del giocatore
        player->Move();

        //Sparo del giocatore
        player->Shoot(PlayerBulletList);

        //Routine del nemico che comprende:
        //Sparo
        //Spostamento
        EnemyRoutine();

        //Controlla se il nemico è stato colpito
        EnemyHitted();

        //Controlla se la navicella del giocatore è stata colpito
        PlayerHitted();

        //Routine del bonus:
        //Spostamento
        //Cancellazione
        //Generazione
        BonusRoutine();

        //Controlla se il giocatore ha catturato il bonus
        BonusCaught();

        //Controlla se c'è stata una collisione tra il nemico e la navicella del giocatore
        Collision();

        //Aggiorno la schermata
        UpdateScreen();

        //Rallento l'esecuzione del loop per evitare un utilizzo intenso della CPU
        usleep(1);
    }
    return false;
}

//Stampa a video la condizione attuale della partita
void Game::UpdateScreen()
{
    //Disegno la finestra di gioco
    game_win->PrintWinBorder();
    main_win.PrintWinBorder();
    PrintInfo();

    //Stampa i colpi sparati dalla navicella del giocatore
    PlayerBulletList.Draw();

    //Stampa i nemici
    EnemyList.Draw();

    //Stampa i colpi dei nemici
    EnemyBulletList.Draw();

    //Stampa la navicella del giocatore
    player->Draw();

    if (bonus)
    {
        //Stampa a video il bonus se esiste
        bonus->Draw();
    }

    //Aggiorno la finestra di gioco
    wrefresh(main_win.GetWin());
}

//Gestisce l'input per lo spastamento della navicella del giocatore
int Game::UserInput()
{
    //Legge l'input da tastiera
    int key = getch();

    switch (key)
    {
        //tasti direzionali
        case KEY_UP:
            player->DecreaseRow();
            break;

        case KEY_DOWN:
            player->IncreaseRow();
            break;

        case KEY_LEFT:
            player->DecreaseColumn();
            break;

        case KEY_RIGHT:
            player->IncreaseColumn();
            break;

        case 'q':
        case 'Q':
            return EXIT;

        case 'p':
        case 'P':
        {
            Menu secondary_menu(*game_win);
            return secondary_menu.GetChoice();
        }

        // Se non viene premuto nessun tasto o un altro tasto diverso dai precedenti ritorana al loop principale
        case ERR:
        default:
            break;
    }
    return 0;
}

//Routine per lo sparo, lo spostamento e la generazione dei nemici
void Game::EnemyRoutine()
{
    //Genera un nuovo nemico
    Enemy *enemyp = new Enemy(game_win);
    EnemyList.Add(enemyp, enemyp->GetGenerationTime());

    //Iterazioni su tutti gli oggetti della lista
    for (EnemyList.SetIter(); !EnemyList.EndList(); EnemyList.SetNext())
    {
        //Sparo
        EnemyList.GetEnemy()->Shoot(EnemyBulletList);  //Generazione del colpo
        for (EnemyBulletList.SetIter(); !EnemyBulletList.EndList(); EnemyBulletList.SetNext())
        {
            EnemyBulletList.GetBullet()->Move();   //Spostamento di tutti i colpi sparati

            //Controlla se ci sono colpi da cancellare
            if (EnemyBulletList.GetBullet()->Remove())
            {
                EnemyBulletList.Remove(EnemyBulletList.GetBullet());
            }
        }

        //Spostamento
        EnemyList.GetEnemy()->Move();
    }

}

//Controlla se è stato colpito il nemico
void Game::EnemyHitted()
{
    //Scansiona tutti i nemici
    for (EnemyList.SetIter(); !EnemyList.EndList(); EnemyList.SetNext())
    {
        //Scanziona tutti i colpi
        for (PlayerBulletList.SetIter(); !PlayerBulletList.EndList(); PlayerBulletList.SetNext())
        {
            //Controllo se il colpo è stato sparato dal giocatore
            if (PlayerBulletList.GetIter()->GetDirection() == NORTH)
            {
                //Confronto le coordinate del colpo con quelle del nemico
                if((PlayerBulletList.GetIter()->GetRow() == EnemyList.GetIter()->GetRow()) &&
                   ((PlayerBulletList.GetIter()->GetColumn() == EnemyList.GetIter()->GetColumn()) ||
                    (PlayerBulletList.GetIter()->GetColumn() == EnemyList.GetIter()->GetColumn()-1) ||
                    (PlayerBulletList.GetIter()->GetColumn() == EnemyList.GetIter()->GetColumn()+1)))
                {
                    EnemyList.GetIter()->DecreaseLife(PlayerBulletList.GetIter()->GetLife());

                    //Cancello il colpo
                    PlayerBulletList.Remove(PlayerBulletList.GetIter());

                    //Controllo se il nemico è morto
                    if (EnemyList.GetIter()->GetLife() == 0)
                    {
                        EnemyList.Remove(EnemyList.GetIter());
                        UpdateScore(20);
                        break;
                    }
                }
            }
        }
    }
}

//Controlla se è stato colpito il giocatore
void Game::PlayerHitted()
{
    //Scanziona tutti i colpi nemici
    for (EnemyBulletList.SetIter(); !EnemyBulletList.EndList(); EnemyBulletList.SetNext())
    {
        //Confronto le coordinate del colpo con quelle della namicella
        if((EnemyBulletList.GetIter()->GetRow() == player->GetRow()) &&
            ((EnemyBulletList.GetIter()->GetColumn() == player->GetColumn()) ||
            (EnemyBulletList.GetIter()->GetColumn() == player->GetColumn()-1) ||
            (EnemyBulletList.GetIter()->GetColumn() == player->GetColumn()-2) ||
            (EnemyBulletList.GetIter()->GetColumn() == player->GetColumn()+1) ||
            (EnemyBulletList.GetIter()->GetColumn() == player->GetColumn()+2)))
        {
            //Cancello il colpo
            EnemyBulletList.Remove(EnemyBulletList.GetIter());

            //life_win->PrintWinBorder();

            player->DecreaseLife(BULLET_DAMAGE);

            //Controllo se la navicella del giocatore è morta
            if (player->GetLife() == 0)
            {
                UpdateScreen();
                Widgets::FinalMessage(*game_win);
                SaveBestScore();
                Globals::End();
            }
        }
    }
}

//Gestione movimento, spostamento e cancellazione del bonus
void Game::BonusRoutine()
{
    //Controllo se esiste un bonus
    if (bonus)
    {
        //Spostamento del bonus
        bonus->Move();

        //Verifico se il bonus è arrivato alla fine della schermata
        //Dovra' quindi essere cancellato
        if (bonus->Remove())
        {
            delete bonus;
            bonus = nullptr;
        }
    }
    else
    {
        //Genera un bonus
        if (bonus->Generation())
        {
            bonus = new Bonus(game_win);
        }
    }
}

//Controlla se il giocatore ha beccato il bonus
void Game::BonusCaught()
{
    if(bonus)
    {
        if (((player->GetRow() == bonus->GetRow()) &&
            ((player->GetColumn() == bonus->GetColumn()) ||
             (player->GetColumn()+1 == bonus->GetColumn()) ||
             (player->GetColumn()-1 == bonus->GetColumn()) ||
             (player->GetColumn()+2 == bonus->GetColumn()) ||
             (player->GetColumn()-2 == bonus->GetColumn()))))
        {
            delete bonus;
            bonus = nullptr;
        }
    }
}

//Controlla se la navicella del giocatore ha avuto una collisione con il nemico
void Game::Collision()
{
    //Controllo se c'è stata una collisione tra il nemico e la navicella
    for(EnemyList.SetIter(); !EnemyList.EndList(); EnemyList.SetNext())
    {
        if (((player->GetRow() == EnemyList.GetIter()->GetRow()) &&
             ((player->GetColumn() == EnemyList.GetIter()->GetColumn()) ||
              (player->GetColumn() == EnemyList.GetIter()->GetColumn()-1) ||
              (player->GetColumn() == EnemyList.GetIter()->GetColumn()+1) ||
              (player->GetColumn()-2 == EnemyList.GetIter()->GetColumn()) ||
              (player->GetColumn()-2 == EnemyList.GetIter()->GetColumn()+1) ||
              (player->GetColumn()+2 == EnemyList.GetIter()->GetColumn()) ||
              (player->GetColumn()+2 == EnemyList.GetIter()->GetColumn()-1))))
        {
            player->DecreaseLife(EnemyList.GetIter()->GetLife());

            //Rimuovo il nemico
            EnemyList.Remove(EnemyList.GetIter());

            //Controllo i punti vita rimasti alla navicella del giocatore
            if(player->GetLife() == 0)
            {
                UpdateScreen();
                Widgets::FinalMessage(*game_win);
                SaveBestScore();
                Globals::End();
            }

            //Aggiorno il punteggio
            UpdateScore(10);
        }
    }
}

//Aggiora il punteggio
void Game::UpdateScore(int value)
{
    score = score + value;
    if (score > bestScore)
    {
        bestScore = score;
    }
}

//Salva il miglior punteggio
void Game::SaveBestScore()
{
    f.Create();
    f.Save(bestScore);
}

//Inizializza la variabile highScore
void Game::SetBestScore()
{
    //Controllo che i file esistano
    if(!f.Exists())
    {
        bestScore = INIT;
    }
    else
    {
        f.Restore(bestScore);
    }
}

//Salva lo stato attuale della partita
void Game::SaveGameStatus()
{
    f.Save(&EnemyList);
    f.Save(*player);
}

//Riprende la partita dal punto in cui è stata interrotta
void Game::ResumeLastMatch()
{
    f.Restore(EnemyList);
    f.Restore(player);
}

//Restituisce un riferimento alla finestra principale
Window &Game::GetMainWin()
{
    return main_win;
}

//Stampa il conteneuto della finestra info_win
void Game::PrintInfo()
{
    werase(info_win->GetWin());
    wprintw(info_win->GetWin(), "\n\n Punteggio: %d\n",score);
    wprintw(info_win->GetWin(), "\n Record: %d\n",bestScore);
    wprintw(info_win->GetWin(), "\n Punti vita: %d\n",player->GetLife());
    wprintw(info_win->GetWin(), "\n Scudo: %d\n",INIT);
    info_win->PrintWinBorder();
}

//Distruttore
Game::~Game()
{
    delete game_win;
    delete info_win;
}
