#include <stdio.h>
int main(){
	extern int a;
	printf("extern 得到的数是 %d\n",a);
	return 0 ;
}
