#include <stdio.h>
#include <string.h>
void tans(int a){
                int i = 0;
                char temp[1000] = {0};
                while(a != 0){
                    temp[i] = a % 2;
                    a /= 2;
                    //printf("%d\n",a);输出整数商
                    i++;
                }
                for(int m=i-1; m >= 0;m--) printf("%d",temp[m]);
                printf("\n");
               
}
int main(){
	int a;
	printf("输入一个数：\n");
        scanf("%d",&a);
	tans(a);
	return 0 ;
}
