#include <stdio.h>
typedef struct T{
	int  *a;
	short b;
}T_Test;
int main(){
	int tmp = sizeof(T_Test); 
	printf("sizeof T_Test is %d\n",tmp);
	return 0;
}
