#include <stdio.h>
#define target 1
//#define target 2		//define 这里是不能更改，或者说宏定义名字不能相同
int main(){
	//target = 2;i		//这里是不能更改，define可以理解为给常数备注
	printf("define 出来的数为%d \n",target);
	return 0;
}
