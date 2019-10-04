#include <stdio.h>
int sort(int weak){
	if(weak == 7) weak = 0;
	return weak;
}
int main(){
	printf("please input a num\n");
	int weak;
	scanf("%d",&weak);
	printf("%d\n",sort(weak));
	return 0;
}
