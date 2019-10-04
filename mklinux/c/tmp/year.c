#include <stdio.h>

int year(int a,int b){
	int s = 0;
	int y_m[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	for(int i = 0; i<a-1;i++ ){
		s += y_m[i];
	}
	return s+b;
}

int main(){
	int a,b;
	printf("请输入月份和日期：\n");
	scanf("%d %d",&a,&b);
	printf("%d\n",year(a,b));
	return 0;
}
