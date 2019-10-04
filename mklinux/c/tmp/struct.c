#include <stdio.h>
typedef struct T{
	char  a;
	short b;
	char  c;
	int   d;
	char  e[3];
}T_Test;
T_Test t;
int main(){
	int tmp = sizeof(T_Test); 
	printf("sizeof T_Test is %d\n",tmp);
	printf("char  a is %p\nshort b is %p\nchar  c is %p\nint   d is %p\nchar  e is %p\n",&t.a, &t.b, &t.c, &t.d, &t.e);
	return 0;
}
