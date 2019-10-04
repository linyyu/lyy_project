#include <stdio.h>
#include <curses.h>
void paint_head(int year,int month,int day){
    attrset(A_BOLD);
	for(int i=0;i<30;i++) printw("%s","-");
	printw("\n");
	attrset(0);
	printw("%13d-%d-%d\n",year,month,day);
	for(int i=0;i<30;i++) printw("%s","-");
	printw("\n");
	char Weak[7][4] = {{"SUN"},{"MON"},{"TUE"},{"WED"},{"THU"},{"FRI"},{"SAT"}};
	for(int i=0;i<7;i++) printw("%4s",Weak[i]);
	printw("\n");
	for(int i=0;i<30;i++) printw("%s","-");
	printw("\n");
}

int main()
{
	initscr();/*初始化屏幕*/
	clear();//清屏函数
	paint_head();

	refresh();
	getch();//获取字符
	endwin();/*关闭curses状态*/
	return 0;
}
