#include <stdio.h>
struct T{
	int a;
	char b;
}s,*p;

int main(){
	s.a = 1;
	s.b = 'a';
	p = &s;
	printf("%d\n",p->a);
	return 0 ;
}
