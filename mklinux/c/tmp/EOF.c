#include <stdio.h>
int main()
{
		    int ch;
			    do {
						        ch=getchar();
								        printf("ch=%d\n", ch ); //输出读返回的ch值，读到EOF会输出-1
										    } while ( ch!=EOF );
	return 0;
}
