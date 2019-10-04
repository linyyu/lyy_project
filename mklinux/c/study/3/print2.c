#include <stdio.h>
int main(){
	unsigned int un = 3000000000;
	short end = 200;
	long big = 65537;
	long long verybig = 12345678908642;
	
	printf("un = %u and not %d\n",un,un);
	printf("end = %hd and %d\n",end,end);
	printf("big = %1d and not %hd\n",big,big);
	printf("berybig = %11d and not %1d\n",verybig,verybig);
	return 0;
}
