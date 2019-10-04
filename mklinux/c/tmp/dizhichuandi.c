 #include <stdio.h>
 #include <stdlib.h>
 
 int func1(int *a,int *b)
 {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
	return 0;
 }
 
 int main()
 {
     int x,y;
	 x = 20;
	 y = 30;
	 func1(&x,&y);
     printf("x is %d\ny is %d\n", x, y);
 }
