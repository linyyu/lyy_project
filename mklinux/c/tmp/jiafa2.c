#include <stdio.h>
int sum(int a ,int b){
	if (a == 0) return b;
	if (b == 0) return a;
	int newa = a ^ b;
	int newb = (a & b) << 1;
	return sum(newa,newb);
}

int main(){
        int a,b;
        printf("输入两个整数：\n");
        scanf("%d%d",&a,&b);
        int res = sum(a,b);
        printf("result:%d\n",res);
        return 0;
}

