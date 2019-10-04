#include <stdio.h>
int main(){
	int a;
	char c;
	printf("请输入字符：\n");
	scanf("%c",&c);
	a = c;
	if(a>47 && a<58) printf("这个字符是数字\n");
	else if(a>64 && a<91)	printf("这个字符是大写字母\n");
	else if(a>96 && a<123) printf("这个字符是小写字母\n");
	else if(a==32) printf("这个字符是空格\n");
	else printf("其他字符\n");
	return 0;
}
