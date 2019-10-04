#include <stdio.h>
int main(){
	extern int a,b;
	extern void print1();
	printf("extern 得到的数是 %d 和 %d\n",a,b);
	print1();
	return 0 ;
}
