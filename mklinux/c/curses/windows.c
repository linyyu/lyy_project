#include<curses.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
		initscr();
		WINDOW* newsreen;
		newsreen = newwin(2,5,2,2);
		box(newsreen, ACS_VLINE, ACS_HLINE);
		
		refresh();
		getch();
		endwin();
		return 0;
}
