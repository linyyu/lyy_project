#include <stdio.h>
#include <curses.h>
#include <time.h>

int zeller(int year,int month){
	int weak = 0;
	int c,y,m,d;
	if(month <= 2){
		c = (year - 1) / 100;
		y = (year - 1) % 100;
		m = month + 12;
		d = 1;
	}
	else{
		c = year / 100;
		y = year % 100;
		m = month;
		d = 1;
	}
	weak = y + y/4 + c/4 - 2*c + 26*(m+1)/10 + d - 1;
	weak %= 7;
	if(weak == 0) weak = 7;
	if(weak < 0 ) weak += 7;
	return weak;
}
int sort(int weak){
	if(weak == 7) weak = 0;
	return weak;
}
void paint_head(int year,int month,int day){
    attrset(A_BOLD);
	move(LINES/2-12,COLS/2-27);
	for(int i=0;i<54;i++) printw("%s","-");
	printw("\n");
	attrset(A_BOLD|COLOR_PAIR(3));
	move(LINES/2-11,COLS/2-27);
	printw("%25d - %d - %d\n",year,month,day);
	attrset(0);
	move(LINES/2-10,COLS/2-27);
	for(int i=0;i<54;i++) printw("%s","-");
	printw("\n");
	attron(A_BOLD|COLOR_PAIR(3));
	char Weak[7][4] = {{"SUN"},{"MON"},{"TUE"},{"WED"},{"THU"},{"FRI"},{"SAT"}};
	move(LINES/2-9,COLS/2-27);
	for(int i=0;i<7;i++) mvprintw(LINES/2-9,COLS/2-25+8*i,"%s\t",Weak[i]);
	attroff(COLOR_PAIR(3));
	printw("\n");
	move(LINES/2-8,COLS/2-27);
	for(int i=0;i<54;i++) printw("%s","-");
	printw("\n");
	printw("\n");
}
void paint_end(){
    move(LINES/2-8+4+10,COLS/2-27);
    attrset(A_BOLD);
	for(int i=0;i<54;i++) printw("%s","-");
	printw("\n");
	attrset(0);
}
void paint_body(int hang,int year,int month,int day,int y_m[]){
    attrset(A_BOLD);
	int tmp = sort(zeller(year,month));
	int last = 0;
	for(int i=0;i<hang;i++){
		//move(LINES/2-6-i,COLS/2-25);
		//打印第一行
		if(i==0){
            //第一行前半段
            move(LINES/2-6,COLS/2-25);
            for(int k=0;k<tmp;k++){
                move(LINES/2-6,COLS/2-25+8*k);
                attrset(0);
                attron(COLOR_PAIR(4));
                printw("%d\t", y_m[month-1]-tmp+k+1 );
                attroff(COLOR_PAIR(4));
            }
            attrset(A_BOLD);
            //第一行后半段（下面类同）
            for(int k=0;k<7-tmp;k++) {
                move(LINES/2-6,COLS/2-25+8*(tmp+k));
                if(day == k+1) {
                    attron(COLOR_PAIR(1));
                    printw("%d",k+1);
                    attroff(COLOR_PAIR(1));
                    printw("\t");
                }
                else{
                    if(k == 6-tmp){
                        attron(COLOR_PAIR(2));
                        printw("%d\t",k+1);
                        attroff(COLOR_PAIR(2));
                    }
                    else printw("%d\t",k+1);
                }
            }
            printw("\n");
            printw("\n");

		}
		//打印最后一行
		else if (i == hang - 1){
			move(LINES/2-8+2*hang,COLS/2-25);
			if((tmp+y_m[month])%7 != 0){
				for(int k=0;k<sort(zeller(year,month+1));k++) {
                    move(LINES/2-8+2*hang,COLS/2-25+8*k);
					if(day == 7-tmp+7*(i-1)+k+1 ){
                        attron(COLOR_PAIR(1));
                        printw("%d", 7-tmp+7*(i-1)+k+1);
                        attroff(COLOR_PAIR(1));
                        printw("\t");
					}
					else{
                        if(k == 0){
                            attron(COLOR_PAIR(2));
                            printw("%d\t", 7-tmp+7*(i-1)+k+1);
                            attroff(COLOR_PAIR(2));
                        }
                        else printw("%d\t", 7-tmp+7*(i-1)+k+1);
					}
				}
				for(int k=0;k<7-sort(zeller(year,month+1));k++){
                    int tmp1 = sort(zeller(year,month+1));
                    move(LINES/2-8+2*hang,COLS/2-25+8*(tmp1+k));
                    attrset(0);
                    attron(COLOR_PAIR(4));
                    printw("%d\t",k+1);
                    attron(COLOR_PAIR(4));
                    if(k == 6 - sort(zeller(year,month+1)) ) last = k+1;
				}
				printw("\n");
				printw("\n");
			}
			else{
				for(int k=0;k<7;k++){
					move(LINES/2-8+2*hang,COLS/2-25+8*k);
					if(day == 7-tmp+7*(i-1)+k+1 ){
                        attron(COLOR_PAIR(1));
                        printw("%d", 7-tmp+7*(i-1)+k+1);
                        attroff(COLOR_PAIR(1));
                        printw("\t");
					}
				    else printw("%d\t", 7-tmp+7*(i-1)+k+1);
				}
				printw("\n");
				printw("\n");
			}
		}
		//打印中间内容
		else{
			move(LINES/2-6+2*i,COLS/2-25);
			for(int k=0;k<7;k++){
				move(LINES/2-6+2*i,COLS/2-25+ 8*k);
				if(day == 7-tmp+7*(i-1)+k+1 ){
                    attron(COLOR_PAIR(1));
                    printw("%d", 7-tmp+7*(i-1)+k+1);
                    attroff(COLOR_PAIR(1));
                    printw("\t");
				}
				else{
                    if( k == 0 || k == 6){
                        attron(COLOR_PAIR(2));
                        printw("%d\t", 7-tmp+7*(i-1)+k+1);
                        attroff(COLOR_PAIR(2));
                    }
                    else printw("%d\t", 7-tmp+7*(i-1)+k+1);
				}
			}
			printw("\n");
		}
	}
	if(hang != 6){
        for(int k=0;k<7;k++){
            move(LINES/2-8+2+10,COLS/2-25+8*k);
            attron(COLOR_PAIR(4));
            printw("%d",last+1+k);
            attroff(COLOR_PAIR(4));
        }
	}
	attrset(0);
}
void paint_cols(){
    attron(A_BOLD);
    for(int i=0;i<17;i++){
        for(int k=0;k<2;k++){
            move(LINES/2-11+i,COLS/2-28+k*(55));
            printw("%s","|");
        }
    }
    attroff(A_BOLD);
}
void paint_right(int X,int Y){
    for(int i=0;i<2;i++) mvprintw(X+i,Y+i,"%c",'\\');
    for(int i=0;i<2;i++) mvprintw(X+2+i,Y+1-i,"%c",'/');
}
void paint_left(int X,int Y){
    for(int i=0;i<2;i++) mvprintw(X+i,Y-63-i,"%c",'/');
    for(int i=0;i<2;i++) mvprintw(X+2+i,Y-64+i,"%c",'\\');
}
int main(){
    initscr();//初始化屏幕
	clear();//清屏函数
    start_color();//开启颜色设置
    keypad(stdscr,TRUE);
    init_pair(1,COLOR_CYAN,COLOR_GREEN);//绿色底色
	init_pair(2,COLOR_RED,COLOR_BLACK);//红色
	init_pair(3,COLOR_MAGENTA,COLOR_BLACK);//紫色
	init_pair(4,COLOR_BLUE,COLOR_BLACK);//蓝色
	init_pair(5,COLOR_YELLOW,COLOR_BLACK);//黄色

    time_t now;
    struct tm *tm_now;
    time(&now);
    tm_now = localtime(&now);
    int year,month,day;
    year = tm_now->tm_year+1900;
    month = tm_now->tm_mon+1;
    day = tm_now->tm_mday;

	int y_m[13] = {31,31,28,31,30,31,30,31,31,30,31,30,31};
	int X=LINES/2-3, Y=COLS/2+31;

    bool button = 1;
	int ch;
    while(button == 1){
        if (year%4==0 && year%100!=0){
		y_m[2] = 29;
        }
        else if (year%400 == 0) y_m[2] = 29;
        else y_m[2] = 28;

        int hang;
        int days = sort(zeller(year,month))+y_m[month];
        if(days % 7 == 0 ) hang = days / 7;
        else hang = days / 7 + 1;

        paint_head(year,month,day);
        paint_body(hang,year,month,day,y_m);
        paint_end();
        paint_cols();
        //paint_left(X,Y);
        //paint_right(X,Y);
        move(LINES/2-8+4+11,COLS/2-27);
        refresh();

        //move(LINES/2-13,COLS/2-28);
        ch = getch();
        clear();
        paint_head(year,month,day);
        paint_end();
        paint_cols();
        //paint_left(X,Y);
        //paint_right(X,Y);
        move(LINES/2-8+4+11,COLS/2-27);
        refresh();

        if(ch == 'f'){
            attron(A_BOLD|COLOR_PAIR(4));
            mvprintw(LINES/2-13,COLS/2-28,"Please input year, month and day             ");
            scanw("%d %d %d",&year,&month,&day);
        }
		else{
			switch(ch){
				case KEY_RIGHT: {
                    month += 1;
                    //printw("%d\n", month);
                    attron(A_BOLD|COLOR_PAIR(5));
                    //paint_right(X,Y);
                    if(month == 13){
                        month = 1;
                        year += 1;
                    }
                    mvprintw(LINES/2-14,COLS/2-28,"today is %d %d %d",year,month,day);
                    break;
				}
				case KEY_LEFT: {
                    month -= 1;
                    //printw("%d\n", month);
                    if(month == 0){
                        month = 12;
                        year -= 1;
                    }
                    attron(A_BOLD|COLOR_PAIR(5));
                    //paint_left(X,Y);
                    mvprintw(LINES/2-14,COLS/2-28,"today is %d %d %d",year,month,day);
                    break;
				}
				case KEY_UP: year -= 1;attron(A_BOLD|COLOR_PAIR(5));mvprintw(LINES/2-14,COLS/2-28,"today is %d %d %d",year,month,day);break;
				case KEY_DOWN: year += 1;attron(A_BOLD|COLOR_PAIR(5));mvprintw(LINES/2-14,COLS/2-28,"today is %d %d %d",year,month,day);break;
				case 27 : button=0;break;
			}
		}
    }

	//getch();//获取字符
	endwin();//关闭curses状态
	return 0;
}
