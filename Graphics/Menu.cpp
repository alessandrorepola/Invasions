/******************************************
* File Menu.cpp                           *
* Implementazione dei metodi per il Menu  *
******************************************/

#include "Menu.h"

//Dimensione del menu
#define MENU_WIDTH 25
#define MENU_HEIGHT 10

Menu::Menu(Window &parent)
{
    //Inizializzo le coordinate iniziali del menu
    startx = INIT;
    starty = INIT;

    //imposto il cursore sulla prima voce per default
    highlight = START_XY;

    choice = INIT;

    startx = (parent.GetWidth() - MENU_WIDTH) / 2;
    if (parent.GetY() == INIT)
    {
        starty = (parent.GetHeight()+5) / 2;
    }
    else
    {
        starty = (parent.GetHeight()-MENU_HEIGHT) / 2;
    }

	menu_win = derwin(parent.GetWin(), MENU_HEIGHT, MENU_WIDTH, starty, startx);
	keypad(menu_win, TRUE);

	SelectChoice(parent);
}

//Gestisce la scelta dell'utente
int Menu::SelectChoice(Window &parent)
{
	PrintMenu(parent);
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
		PrintMenu(parent);
		if(choice != INIT)
			break;
	}
	clrtoeol();
	refresh();
	return choice;
}

//Stampa il Menu
void Menu::PrintMenu(Window &parent)
{
    int x, y, i;

	x = 2;
	y = 2;
	werase(menu_win);
	box(menu_win, INIT, INIT);
	for(i = INIT; i < N_CHOICES; ++i)
	{
	    if(highlight == i + START_XY)
        {
            wattron(menu_win, COLOR_PAIR(CYAN));
        }

	    if (parent.GetX() == INIT)
        {
            mvwprintw(menu_win, y, x, "%s", first_menu_choices[i]);
        }
        else
        {
            mvwprintw(menu_win, y, x, "%s", secondary_menu_choices[i]);
        }

        wattrset(menu_win, COLOR_PAIR(WHITE));
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
