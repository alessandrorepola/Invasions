/******************************************
* File Menu.cpp                           *
* Implementazione dei metodi per il Menu  *
******************************************/

#include "Menu.h"

Menu::Menu()
{
    //Inizializzo le coordinate iniziali del menu
    startx = INIT;
    starty = INIT;

    //imposto il cursore sulla prima voce per default
    highlight = 1;

    choice = INIT;
}

//Gestisce la scelta dell'utente
void Menu::SelectChoice()
{
    startx = (80 - MENU_LENGHT) / 2;
	starty = (24 - MENU_HIGH) / 2;

	menu_win = newwin(MENU_HIGH, MENU_LENGHT, starty, startx);
	keypad(menu_win, TRUE);

	PrintMenu();
	while(1)
	{
	    int c = wgetch(menu_win);
		switch(c)
		{
		    case KEY_UP:
				if(highlight == 1)
					highlight = N_CHOICES;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == N_CHOICES)
					highlight = 1;
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
}

//Stampa il Menu
void Menu::PrintMenu()
{
    int x, y, i;

	x = 2;
	y = 2;
	box(menu_win, INIT, INIT);
	for(i = INIT; i < N_CHOICES; ++i)
	{	if(highlight == i + 1)
		{	wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(menu_win);
}
