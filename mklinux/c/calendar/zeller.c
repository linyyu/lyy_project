#include <stdio.h>
int zeller(int year,int month){
        int c,d=1,weekday;
        if(month==1||month==2)
           month+=12,year=year-1;
           weekday=(1+2*month+3*(month+1)/5+year+year/4-year/100+year/400+1)%7;
        if (weekday==7) weekday=0;
        return weekday;
}
/*int zeller(int year,int month){
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
	return weak;
}/*
/*int sort(int weak){
	if(weak == 7) weak = 0;
	return weak;
}*/
int main()
{
	int year,month,day;
	printf("please input y_M_D\n");
	scanf("%d %d %d",&year,&month,&day);

	//printf("%d\n",sort(zeller(year,month,day)));
	printf("%d\n",zeller(year,month));
	return 0;
}
