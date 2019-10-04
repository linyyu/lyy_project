#include <stdio.h>
#define pai 3.14
#define HELL
int main(){
	printf("hello world!\n");
	#ifdef HELL
	printf("hello HELL\n");
	#else
	printf("not define HELL\n");
	#endif
	int a;
	a = pai;
	printf("pai_a:%d",a);
	return 0;
}
