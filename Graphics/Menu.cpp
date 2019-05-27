/******************************************
* File Menu.cpp                           *
* Implementazione dei metodi per il Menu  *
******************************************/

#include "Menu.h"

Menu::Menu(int type)
{
    //Inizializzo le coordinate iniziali del menu
    startx = INIT;
    starty = INIT;

    //imposto il cursore sulla prima voce per default
    highlight = START_XY;

    choice = INIT;

    menu_type = type;

    startx = (GAME_WIN_LENGTH - MENU_LENGHT) / 2;
	starty = (GAME_WIN_HIGH - MENU_HIGH) / 2;

	menu_win = newwin(MENU_HIGH, MENU_LENGHT, starty, startx);
	keypad(menu_win, TRUE);

	SelectChoice();
}

//Gestisce la scelta dell'utente
int Menu::SelectChoice()
{
	PrintMenu();
	while(TRUE)
	{
	    int c = wgetch(menu_win);
		switch(c)
		{
		    case KEY_UP:
				if(highlight == START_XY)
					highlight = N_CHOICES;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == N_CHOICES)
					highlight = START_XY;
				else
					++highlight;
				break;
			case 10:
				choice = highlight;
				break;
			default:
				break;
		}
		PrintMenu();
		if(choice != INIT)
			break;
	}
	clrtoeol();
	refresh();
	return choice;
}

//Stampa il Menu
void Menu::PrintMenu()
{
    int x, y, i;

	x = 2;
	y = 2;
	box(menu_win, INIT, INIT);
	for(i = INIT; i < N_CHOICES; ++i)
	{	if(highlight == i + START_XY)
		{	wattron(menu_win, A_REVERSE);
            if (menu_type == FIRST_MENU)
            {
                mvwprintw(menu_win, y, x, "%s", first_menu_choices[i]);
            }
            else
            {
                mvwprintw(menu_win, y, x, "%s", secondary_menu_choices[i]);
            }
			wattroff(menu_win, A_REVERSE);
		}
		else
        {
            if (menu_type == FIRST_MENU)
            {
                mvwprintw(menu_win, y, x, "%s", first_menu_choices[i]);
            }
            else
            {
                mvwprintw(menu_win, y, x, "%s", secondary_menu_choices[i]);
            }
        }
        ++y;
	}
	wrefresh(menu_win);
}

//Restituisce la scelta dell'utente
int Menu::GetChoice()
{
    return choice;
}

//Distruttore
Menu::~Menu()
{
    delwin(menu_win);
}
