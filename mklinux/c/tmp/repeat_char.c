#include<stdio.h>
#include<string.h>

void repeat_char(char *arr){
	int len, i, j, count;	
	count = 1;
	len = strlen(arr);
	char tmp[len];
	tmp[0] = arr[0];
	for(i = 1; i < len; i++){
		j = 0;
		for(;j < count;){
			if(tmp[j] != arr[i]){
				j++;
			}
			else{
				break;
			}
			tmp[count++] = arr[i];
		}
	}
	for(j = 0; j < count; j++){
		printf("%c", tmp[count -j]);
	}
}


int main(){
	char ch[] = "google";
	repeat_char(ch);
	return 0;	
}
