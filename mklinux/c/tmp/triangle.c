#include <stdio.h>
int main(){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if (a+b>c && a+c>b && b+c>a){
		printf("这三个整数可以构成三角形\n");
                if ((a^2)+(b^2)==(c^2) || (c^2)+(b^2)==(a^2) || (a^2)+(c^2)==(b^2) ) printf("是一个直角三角形\n");
                else printf("不是一个直角三角形\n");
        }
        else printf("这三个整数不可以构成三角形\n");
        return 0;
}

