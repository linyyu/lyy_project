#include <stdio.h>
int sum(int a ,int b){
	int sum = 0 ,carry = 0;
	do {
		sum = a ^ b;
		carry = (a & b) << 1;
		a = sum;
		b = carry;
	}while( b != 0);
	return a;
}

int main(){
	int a,b;
	printf("输入两个整数：\n");
	scanf("%d%d",&a,&b);
	int res = sum(a,b);
	printf("result:%d\n",res);
	return 0;
}
