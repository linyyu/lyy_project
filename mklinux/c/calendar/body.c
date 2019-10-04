#include <stdio.h>
#include <curses.h>
int zeller(int year,int month,int day);
int sort(int weak);

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
