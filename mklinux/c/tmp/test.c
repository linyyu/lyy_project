#include <stdio.h>
#include <curses.h>

//	常见的颜色设置程序
//	
//	start_color();                                                        
//	开启彩显模式
//	attron(COLOR_PAIR(1));                                     
//	开启一个颜色对
//	init_pair(1, COLOR_RED, COLOR_WRITE);       
//	初始化这个颜色对, 前景色为红, 背景色为白
//	...                                                                          
//	中间是你要打印的字符
//	attroff(COLOR_PAIR(1));                                     
//	关闭该颜色对

int main()
{	
	initscr();/*初始化屏幕*/ 
	clear();//清屏函数


	//！！！！
	//颜色要先开(即在initscr或者clear后面就要先编译了)，
	//先开时整个界面都是灰白色；颜色后开界面主体为原先的紫色,灰白为辅。
	
	start_color();//开启颜色设置
	init_pair(1,COLOR_WHITE,COLOR_MAGENTA);//颜色初始化
	init_pair(2,COLOR_CYAN,COLOR_MAGENTA);
	attron(COLOR_PAIR(1));/*start color show*/
	move(4 , 10);//移动光标。屏幕的行宽和列宽在curses库中定义为(LINES-1，COLS-1)
	printw("This is color颜色\n");
	
	//move(LINES/2,COLS/2);/*光标居中*/
	printw("1\t 2\t 3\t 4\t 5\t 6\t 7\t\n");//打印函数
	printw("%4d%4d%4d%4d%4d%4d%4d\n",1,2,3,4,5,6,7);//打印函数
	//mvprintw(10,10,"%d\n",123);//打印函数
	refresh();//刷新屏幕
	addstr("Hello, world\n");//打印字符串
	//attrset(A_UNDERLINE);//下滑线
	printw("A word in");
	//attrset(A_BOLD);//字体加粗
	printw("boldface");
	//attrset(0);//关闭所有的属性
	printw("really stands out.\n");
		
	attron(COLOR_PAIR(2));
	addstr("Red and Bule\n");
	//move(LINES-1, 0); 
	attroff(COLOR_PAIR(2)|COLOR_PAIR(1));/*close color show*/
	addstr("After attron , Red and Bule?\n");
	
	
	refresh();
	
	getch();//获取字符
	endwin();/*关闭curses状态*/
	return 0;
}
