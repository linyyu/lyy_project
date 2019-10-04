#include <stdio.h>
#include <math.h>
int main(){
	float a;
	printf("请输入一个二进制小数\n");
	scanf("%f",&a);
	int tmp = 0;
	while(a < 1){	
		a *= 10;
		tmp++;
	}
	printf("共有%d位小数\n",tmp);
/*	int store[tmp];
	int i=0;
	int tmp1 = a * pow(10,tmp*2);
	printf("tmp1 %d\n",tmp1);
	for(int k=tmp;k>=0;k--){
		tmp1 %= 10;
		store[i] = a;
		i++;
	}
	int s=0;
	for(int k=0;k<tmp;k++){
		s = s + store[k]*pow(2,-k);
	}
	printf("这个数的十进制为%d\n",s);*/
	return 0;
}
