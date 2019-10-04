#include <stdio.h>
int main(){
	char str[4] = {'a','b','c','d'};
	int i = 2;
	printf("%p\n",str);
	printf("%d\n",i[str]);
	return 0;
}
