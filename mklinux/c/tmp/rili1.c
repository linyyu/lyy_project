#include <stdio.h>

//设置余数yu
int yu(int a,int y_m[]){	
	if(a == 0) return 1;
	else{
		return (yu(a-1,y_m)+y_m[a-1])%7;
	}
}

//打印日历头部
void paint_head(){
	for(int k=0;k<7;k++) printf("%s","…………………");
	printf("……\n");
	printf("日\t");
	printf("一\t");
	printf("二\t");
	printf("三\t");
	printf("四\t");
	printf("五\t");
	printf("六\t");
	printf("\n");
	for(int k=0;k<7;k++) printf("%s","…………………");
	printf("……\n");
}

//打印日历内容
void paint_body(int hang,int a,int b,int y_m[]){
	for(int i=0;i<hang;i++){
		//打印第一行
		if(i==0){
			if(a != 1 ){
				//第一行前半段
				for(int k=0;k<yu(a-1,y_m);k++) printf("%d\t", y_m[a-2]-yu(a-1,y_m)+k+1 );
				//第一行后半段（下面类同）
				for(int k=0;k<7-yu(a-1,y_m);k++) {
					if(b == k+1) printf("%d*\t",k+1);
					else printf("%d\t",k+1);
				}
				printf("\n");
			}
			else {
				for(int k=0;k<yu(a-1,y_m);k++) printf("%d\t", y_m[11]-yu(a-1,y_m)+k+1 );
				for(int k=0;k<7-yu(a-1,y_m);k++){
					if(b == k+1) printf("%d*\t",k+1);
					else printf("%d\t",k+1);
				}
				printf("\n");
			}
		}
		//打印最后一行
		else if (i == hang - 1){
			if((yu(a-1,y_m)+y_m[a-1])%7 != 0){
				for(int k=0;k<yu(a,y_m);k++) {
					if(b == 7-yu(a-1,y_m)+7*(i-1)+k+1 ) printf("%d*\t", 7-yu(a-1,y_m)+7*(i-1)+k+1);
					else printf("%d\t", 7-yu(a-1,y_m)+7*(i-1)+k+1);
				}
				for(int k=0;k<7-yu(a,y_m);k++) printf("%d\t",k+1);
				printf("\n");
			}
			else{
				for(int k=0;k<7;k++){
					if(b == 7-yu(a-1,y_m)+7*(i-1)+k+1 ) printf("%d*\t", 7-yu(a-1,y_m)+7*(i-1)+k+1);
				    else printf("%d\t", 7-yu(a-1,y_m)+7*(i-1)+k+1);
				}
				printf("\n");
			}
		}
		//打印中间内容
		else{
			for(int k=0;k<7;k++){
				if(b == 7-yu(a-1,y_m)+7*(i-1)+k+1 ) printf("%d*\t", 7-yu(a-1,y_m)+7*(i-1)+k+1);
				else printf("%d\t", 7-yu(a-1,y_m)+7*(i-1)+k+1);
			}
			printf("\n");
		}
	}	
}

int main(){
	int y_m[13000]={31,28,31,30,31,30,31,31,30,31,30,31};
	int y,a,b;
	printf("\n");
	printf("该程序可查询1900年以后的所有日历！\n");
	printf("输入年份月份日期：\n");
	printf("年份：");
	scanf("%d",&y);
	printf("月份：");
	scanf("%d",&a);
	printf("日期：");
	scanf("%d",&b);
	
	int d = a + (y-1900)*12;
	for(int k=13;k<d+1;k++){
		if(k%12 == 2){
			y = 1900 + k/12;
			if( y%4==0 && y%100!=0 )  y_m[k-1] = 29;
			else if(y%400 == 0)  y_m[k-1] = 29;
			else y_m[k-1] = 28;		
		}
		else if(k%12 == 0)  y_m[k-1] = y_m[11];
		else  y_m[k-1] =y_m[k%12-1];
	}
	
	int hang , days = yu(d-1,y_m)+y_m[d-1];
	if(days % 7 == 0 ) hang = days / 7;
	else hang = days / 7 + 1;
	printf(" \t \t %d 年 %d 月 %d 日\t \t ",y,a,b);
	printf("\n");
	paint_head();
	paint_body(hang,d,b,y_m);
	for(int k=0;k<7;k++) printf("%s","…………………");
	printf("……\n");
	return 0;
}
