#include<stdio.h>

int main(int argc, int *argv[]){
	printf("argc = %d\n", argc);
	
	for(int i = 0; i < argc; i++ ){
		printf("i = %d, *(argv[%d]) = %s \n", i, i, (char *)argv[i]);
	}
	return 0;
}
