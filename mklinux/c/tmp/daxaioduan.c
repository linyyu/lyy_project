#include<stdio.h>
/*1、通过栈和data段比较确定栈地址高低
 2、在union中，char c首地址与int a内存共用。
3、判断：cahr把int分成4块。通过地址+1（即&un.a+1 与 &un.a)对int各块进行分析来确定位置，进而确定大小端。
 */

union UN
{
	int a;
	char c;
}un;

int main()
{
	union UN un;
	static int a = 10;
	printf("%p\n", &un.a);
	printf("%p\n", &un.c+1);
	printf("%p\n", &un);
	printf("%p\n", &a);
	un.a=540;
	if(*(&un.c+1) == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}
