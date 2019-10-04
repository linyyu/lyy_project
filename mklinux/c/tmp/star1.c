#include <stdio.h>
int main(){
	int a;
	printf("输入行数：\n");
	scanf("%d",&a);
	for(int k=1;k<=a;k++){
		for(int i=0;i<a-k;i++) printf(" ");
		for(int i=0;i<2*k-1;i++) printf("*");
		printf("\n");
	}
	return 0;
}
