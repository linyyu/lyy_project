#include <stdio.h>
int main(){
	const int *a;//声明,其作用跟 int const *b; 一样
	int tmp = 666;
	a = &tmp;//初始化

	printf("显示地址所指向的内存：%d \n",*a);
	
	//const int *p 后 *p是一个常量
	*a = 700;//这里出错了
	printf("输出：%d\n",tmp);
	
	//b指向的内存 tmp 自身值传递
	tmp = *a +1;
	printf("通过地址传递改变tmp的值：%d\n",tmp);

	return 0;
}
/*	(1) const函数是指 可读不可改函数
 	(2) 以*a 和 tmp 为例,这里涉及三个地址：
 		指针a的地址、a指针所指向内存的地址、tmp变量的地址
		const int *a 中 const的部分是 *a
		在运行完 a = &tmp; 后, 第二个地址的内容变成内存tmp里的内容
		至此 const 完成。 第二个内存的值将不能在改

 */
