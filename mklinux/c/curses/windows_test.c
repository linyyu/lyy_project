#include<curses.h>
#include<stdio.h>
int main()
{
		initscr();
		box(stdscr, ACS_VLINE, ACS_HLINE);

		WINDOW* midscreen;
		midscreen = subwin(stdscr,  5  ,  80  , 5  ,  7 );
		box(midscreen,'|','-');

		int width = 80;
		WINDOW *midscreen1;
		midscreen1 = newwin(  5  ,  width  , 11  ,  7 );
		box(midscreen1,'|','-');
		mvwaddstr(midscreen1,1,1, "newwin");
		refresh();
//		wrefresh(midscreen1);
		
		wgetch(midscreen1);
		wclear(midscreen1);
		box(midscreen1,'|','-');
//		wrefresh(midscreen1);
		
		wgetch(midscreen1);
		wclear(midscreen1);
		wrefresh(midscreen1);
		delwin(midscreen1);
		refresh();
		
		move(LINES/2, COLS/2);
		waddstr(stdscr, "hello, world!");
		refresh();
		getch();

		endwin();
		return 0;
}
