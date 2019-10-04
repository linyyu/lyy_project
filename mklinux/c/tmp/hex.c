#include<stdio.h>
#include<string.h>
int *hex(int num){
	int i = 0;
	int  arr[20] = {0};
	
	int temp = num%2;
	num = num/2;
	if(num == 0){
		return ;
	}
	hex(num);
	arr[i] = temp;
	i++;
	return arr;
}

int main(){
	int arr[20] = {0};

	strcpy((char*)arr, (char *)hex(6));

	for(int i = 0; i < 20; i++){
		printf("%d", arr[20]);
	}	
}
