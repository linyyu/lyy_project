#include <stdio.h>

int dele1(int len, int a ,char arr[]){
    for(int i = a-1;i<len;i++){
        arr[i] = arr[i+1];
    }
	return 0;
}

int main(){
	int arr[10] = {1,2,-1,3,-5,-6,4,-9,5,-10};
	int len = sizeof(arr)/sizeof(*arr);
	for(int i=0; i<len; i++){
		if(arr[i]<0){
			dele1(len,i+1,arr);
		}
	}
	int len1 = sizeof(arr) / sizeof(arr[0]);
	for(int i=0; i<len1; i++) printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
