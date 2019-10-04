#include <stdio.h>
#include <curses.h>

int main(){	
	initscr();
	WINDOW* midscreen;
	midscreen = newwin(5,10,3,3);
	wprintw(midscreen,"ONE");


	getch();
	endwin();
	return 0;	
}
