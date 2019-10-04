#include <stdio.h>

//设置余数yu
int yu(int y,int a,int y_m[]){	
//	int m = d - (y-2019)*12;
	if(a == 0) return 2;
	else{
		//int tmp = a;
		if (a>12){
			if(a%12 == 2){
				if( y%4==0 && y%100!=0 ) y_m[a-1] = 29;
			    else if (y%400 == 0) y_m[a-1] = 29;
				else y_m[a-1] = 28;		
			}
			else if (a%12 == 0) y_m[a-1] = y_m[11];
			else y_m[a-1] =y_m[a%12-1];
		}

		return (yu(y,a-1,y_m)+y_m[a-1])%7;
	}
}
int main(){
	int y,a;
	scanf("%d %d",&y,&a);
	int y_m[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	//if( y%4==0 && y%100!=0 ) y_m[1] = 29;
	//if (y%400 == 0) y_m[1] = 29;
	
	//printf("%d\n",y_m[1]);
	//printf("%d\n",a);
	int d = a + (y-2019)*12;
	printf("%d\n",d);
	printf("%d\n",yu(y,d,y_m));
	
//	for(int k = 0;k<d;k++){
//		printf("%d ",y_m[k]);
//	}
//	printf("\n");

	return 0;
}
