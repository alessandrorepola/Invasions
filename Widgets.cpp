//File Widgets.cpp

#include "Widgets.h"

#define TIME 5000

//Banner iniziale
void Widgets::Banner(WINDOW *win)
{
    short row = 0;

    wattron(win,COLOR_PAIR(ORANGE));
    mvwprintw(win, ++row, START_XY, "\t\t    _________ _                 _______  _______ _________ _______  _        _______");
    mvwprintw(win, ++row, START_XY, "\t\t    \\__   __/( (    /||\\     /|(  ___  )(  ____ \\\\__   __/(  ___  )( (    /|(  ____ \\");
    mvwprintw(win, ++row, START_XY, "\t\t       ) (   |  \\  ( || )   ( || (   ) || (    \\/   ) (   | (   ) ||  \\  ( || (    \\/");
    mvwprintw(win, ++row, START_XY, "\t\t       | |   |   \\ | || |   | || (___) || (_____    | |   | |   | ||   \\ | || (_____ ");
    mvwprintw(win, ++row, START_XY, "\t\t       | |   | (\\ \\) |( (   ) )|  ___  |(_____  )   | |   | |   | || (\\ \\) |(_____  )");
    mvwprintw(win, ++row, START_XY, "\t\t       | |   | | \\   | \\ \\_/ / | (   ) |      ) |   | |   | |   | || | \\   |      ) |");
    mvwprintw(win, ++row, START_XY, "\t\t    ___) (___| )  \\  |  \\   /  | )   ( |/\\____) |___) (___| (___) || )  \\  |/\\____) |");
    mvwprintw(win, ++row, START_XY, "\t\t    \\_______/|/    )_)   \\_/   |/     \\|\\_______)\\_______/(_______)|/    )_)\\_______)");
    wattrset(win,COLOR_PAIR(WHITE));
}

//Messaggio iniziale
void Widgets::StartMessage(WINDOW *win)
{
    Window start_message(win, 29, 12, 60, 7);
    wprintw(start_message.GetWin(), "\n\tGuerriero Spaziale benvenuto in Invasions\n   Difendi l'universo dagli alieni e conquista la gloria\n\t\t     COSA ASPETTI!!!");
    start_message.PrintWinBorder();
    wrefresh(start_message.GetWin());
}

//Stampa a video l'Help
void Widgets::Help(Window parent)
{
    Window help_win(parent.GetWin(), parent.GetWidth()/4, parent.GetHeight()/4, parent.GetWidth()/2, parent.GetHeight()/2);
    werase(parent.GetWin());
    wattrset(help_win.GetWin(), COLOR_PAIR(CYAN));
    wprintw(help_win.GetWin(), "\n                  Comandi di gioco\n");
    wprintw(help_win.GetWin(), "\n      Comando                     Tasto\n");
    wattrset(help_win.GetWin(), COLOR_PAIR(WHITE));
    wprintw(help_win.GetWin(), "\n      Sopra:                        "); waddch(help_win.GetWin(),ACS_UARROW);
    wprintw(help_win.GetWin(), "\n      Sotto:                        "); waddch(help_win.GetWin(),ACS_DARROW);
    wprintw(help_win.GetWin(), "\n      Destra:                       "); waddch(help_win.GetWin(),ACS_RARROW);
    wprintw(help_win.GetWin(), "\n      Sinistra:                     "); waddch(help_win.GetWin(),ACS_LARROW);
    wprintw(help_win.GetWin(), "\n      Pausa:                        p");
    wprintw(help_win.GetWin(), "\n      Esci:                         q");
    wattrset(help_win.GetWin(), COLOR_PAIR(CYAN));
    wprintw(help_win.GetWin(), "\n\n                  Comandi del menu\n");
    wattrset(help_win.GetWin(), COLOR_PAIR(WHITE));
    wprintw(help_win.GetWin(), "\n      Voce Precedente:              "); waddch(help_win.GetWin(),ACS_UARROW);
    wprintw(help_win.GetWin(), "\n      Voce Successiva:              "); waddch(help_win.GetWin(),ACS_DARROW);
    wprintw(help_win.GetWin(), "\n      Scegli:                     Enter");

    help_win.PrintWinBorder();
    parent.PrintWinBorder();
    wattrset(parent.GetWin(), COLOR_PAIR(BLUE));
    mvwprintw(parent.GetWin(), 9, 30, " GUIDA ");
    wattrset(parent.GetWin(), COLOR_PAIR(WHITE));
    wrefresh(parent.GetWin());
    getchar();
}

//Messaggio finale
void Widgets::FinalMessage(Window win)
{
    int row = win.GetHeight()/3.5;
    int column = win.GetWidth()/3;

    attrset(COLOR_PAIR(MAGENTA));
    mvprintw(row,column," _______  _______  _______  _______       ");
    mvprintw(++row,column,"(  ____ \\(  ___  )(       )(  ____ \\  ");
    mvprintw(++row,column,"| (    \\/| (   ) || () () || (    \\/  ");
    mvprintw(++row,column,"| |      | (___) || || || || (__        ");
    mvprintw(++row,column,"| | ____ |  ___  || |(_)| ||  __)       ");
    mvprintw(++row,column,"| | \\_  )| (   ) || |   | || (         ");
    mvprintw(++row,column,"| (___) || )   ( || )   ( || (____/\\   ");
    mvprintw(++row,column,"(_______)|/     \\||/     \\|(_______/  ");
    mvprintw(++row,column," _______           _______  _______     ");
    mvprintw(++row,column,"(  ___  )|\\     /|(  ____ \\(  ____ )  ");
    mvprintw(++row,column,"| (   ) || )   ( || (    \\/| (    )|   ");
    mvprintw(++row,column,"| |   | || |   | || (__    | (____)|    ");
    mvprintw(++row,column,"| |   | |( (   ) )|  __)   |     __)    ");
    mvprintw(++row,column,"| |   | | \\ \\_/ / | (      | (\\ (    ");
    mvprintw(++row,column,"| (___) |  \\   /  | (____/\\| ) \\ \\__");
    mvprintw(++row,column,"(_______)   \\_/   (_______/|/   \\__/  ");
    attrset(COLOR_PAIR(WHITE));
    refresh();
    delay_output(TIME);
}
