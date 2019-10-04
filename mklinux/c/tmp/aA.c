#include<stdio.h>

int main(){
	char num;
	printf("请输入一个小写字母：");
	while(1){
		scanf("%c",&num);
		if(num < 'a' || num > 'z'){
			printf("输入的字符不是小写,重新输入..\n");
			getchar();
		}
		else{
			printf("对应大写字母为%c\n", num-32);
			break;
		}
	}
	return 0;
}
