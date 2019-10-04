#include <stdio.h>
int main(){
	static int a = 1;
	static int b;
	b = a;
	printf("static int b = %d\n",b);
	return 0;
}
