#include <stdio.h>
#include <curses.h>

int main(){
	initscr();//初始化屏幕
	clear();//清屏函数
    	start_color();//开启颜色设置
	init_pair(1,COLOR_WHITE,COLOR_MAGENTA);//颜色初始化
	init_pair(2,COLOR_CYAN,COLOR_MAGENTA);
    	keypad(stdscr,TRUE);

    	int year,month,day;
	printw("please input year , month and day     ");
	scanw("%d %d %d",&year,&month,&day);
	//int ch = getch();
	//printw("%c\n",(char)ch);
	//printw("%d\n",ch);
	bool button = 1;
	int ch;
    while(button){

        ch = getch();
		if(ch == 'f'){
			printw("Plese input again: ");
			scanw("%d %d %d",&year,&month,&day);
			printw("%d %d %d\n",year,month,day);
		}
		else{
			switch(ch){
				case KEY_RIGHT: month += 1;printw("%d\n", month); break;
				case KEY_LEFT: month -= 1;printw("%d\n", month); break;
				case KEY_UP: year -= 1;printw("%d\n",year);break;
				case KEY_DOWN: year += 1;printw("%d\n",year); break;
				case 27 : button=0;break;
			}
		}
    }

	//getch();//获取字符
	endwin();//关闭curses状态
	return 0;
}
