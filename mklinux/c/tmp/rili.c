#include <stdio.h>
//设置余数yu
int yu(int a){
	int y_m[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if(a == 0) return 2;
	else return (yu(a-1)+y_m[a-1])%7;
}
//设置日历头
void paint_head(){
	int week[] = {1,2,3,4,5,6,7};
	for(int k=0;k<7;k++) printf("%d\t",week[k]);
	printf("\n");
	for(int k=0;k<7;k++) printf("%s\t","……");
	printf("\n");
}
//设置日历内容
void paint_body(int hang,int a,int y_m[]){
	for(int i=0;i<hang;i++){
		if(i==0){
			for(int k=0;k<yu(a-1);k++) printf("%d\t", y_m[a-2]-yu(a-1)+k+1 );
			for(int k=0;k<7-yu(a-1);k++) printf("%d\t",k+1);
			printf("\n");
		}
		else if (i == hang - 1){
			for(int k=0;k<yu(a);k++) printf("%d\t", 7-yu(a-1)+7*(i-1)+k+1);
			for(int k=0;k<7-yu(a);k++) printf("%d\t",k+1);
			printf("\n");
		}
		else{
			for(int k=0;k<7;k++) printf("%d\t", 7-yu(a-1)+7*(i-1)+k+1);
			printf("\n");
		}
	}	
}

int main(){
	int y_m[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int a,b;
	printf("输入月份日期：\n");
	scanf("%d %d",&a,&b);
	int hang , days = yu(a-1)+y_m[a-1];
	if(days % 7 == 0 ) hang = days / 7;
	else hang = days / 7 + 1;

	paint_head();
	paint_body(hang,a,y_m);

	return 0;
}
