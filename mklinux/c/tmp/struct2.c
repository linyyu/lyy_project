#include <stdio.h>
typedef struct T{
	char  a;
	short b;
	char  c;
	int   d;
}T_Test;
T_Test t;
int main(){
	int tmp = sizeof(T_Test); 
	printf("sizeof T_Test is %d\n",tmp);
	return 0;
}
