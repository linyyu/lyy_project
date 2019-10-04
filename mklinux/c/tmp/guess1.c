#include <stdio.h>
#include <stdlib.h>//刚开始忘了这个头文件
int main(){
	int num = rand() % 100 + 1;
	printf("请猜一个1～100的整数：\n");
	for(int i=0; i<5;i++){
		int a;
		scanf("%d",&a);
		if(a>num) printf("大了，请重新输入：\n");
		else if (a < num) printf("小了，请重新输入：\n");
		else {
			printf("恭喜你答对了\n");
			break;
		}
	}
	return 0;
}
