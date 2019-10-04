#include <stdio.h>
#include <curses.h>
int zeller(int year,int month,int day){
	int weak = 0;
	int c,y,m,d;
	if(month <= 2){
		c = (year - 1) / 100;
		y = (year - 1) % 100;
		m = month + 12;
		d = day;
	}
	else{
		c = year / 100;
		y = year % 100;
		m = month;
		d = day;
	}
	weak = y + y/4 + c/4 - 2*c + 26*(m+1)/10 + d - 1;
	weak %= 7;
	if(weak == 0) weak = 7;
	return weak;
}
int sort(int weak){
	if(weak == 7) weak = 0;
	return weak;
}

int main()
{	
	int year,month,day;
	printf("please input y_M_D\n");
	scanf("%d %d %d",&year,&month,&day);
	int tmp = sort(zeller(year,month,day));
	for(int k=0;k<tmp;k++){
		printf("%4d",31-tmp+1+k);
	}
	for(int k=0;k<7-tmp;k++) printf("%4d",k+1);
	printf("\n");

	//printf("%d\n",zeller(year,month,day));
	return 0;
}
