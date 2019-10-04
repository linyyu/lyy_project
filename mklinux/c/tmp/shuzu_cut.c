#include <stdio.h>
#include <string.h>
//删除第a个元素
void dele(int a ,char tmp[]){
	int k = strlen(tmp);
    for(int i = a-1;i<k;i++){
        tmp[i] = tmp[i+1];
    }
}
//删除重复的元素
int main(){
    char tmp[100] = "google";
    printf("输入字符串\n");
    scanf("%s",tmp);
	int m = strlen(tmp);
	for(int k=0;k<m;k++){
		for(int j=k;j<m;j++){
			if( j!=k && tmp[k]==tmp[j]){
				dele(j+1,tmp);
			}
		}
		m = strlen(tmp);
	}
    printf("%s\n",tmp);
    printf("%d\n",m);
    return 0;
}

