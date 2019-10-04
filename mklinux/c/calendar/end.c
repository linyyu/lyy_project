#include <stdio.h>
#include <curses.h>


int main()
{	
	initscr();/*初始化屏幕*/ 
	clear();//清屏函数
	for(int i=0;i<30;i++) printw("%s","-");
	printw("\n");

	refresh();
	getch();//获取字符
	endwin();/*关闭curses状态*/
	return 0;
}
