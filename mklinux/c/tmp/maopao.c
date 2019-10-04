#include <stdio.h>
int main(){
	int a[10] ={2,3,1,0,8,12,11,45,22,666};
	for(int i=0;i<10;i++){
		for(int j=0;j<9-i;j++){
			if(a[j]>a[j+1]){
				int tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
			else continue;
		}
	}
	for(int i=0;i<10;i++) printf("%d ",a[i]);
	printf("\n");
	return 0;
}
