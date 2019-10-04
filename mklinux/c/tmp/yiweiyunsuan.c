#include <stdio.h>
int main(){
	char a = -3;
	char b = a;
	a <<= 1;
	printf("a=%d\na << 1 = %d\n",b,a);
	return 0;
}
