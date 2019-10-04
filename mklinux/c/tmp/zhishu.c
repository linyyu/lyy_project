#include <stdio.h>
#include <math.h>
//输出1～a以内所有的质数（开方）
void  zhishu_chaxun(int k){
	double b = k; 
	double tmp = sqrt(b);
	int tmp1 = (int)tmp;
	if(k == 2) printf("%3d 是质数\n",k);;
	for(int i=2; i<tmp1+2; i++){
		if(k % i == 0){
			break;
		}
		else if(i == tmp1+1){
			if (k != 1) printf("%3d 是质数\n",k);
		}
	}
}
//对1～a以内的数进行质数判断(没有开平方)
void  zhishu_pangduan(int a){
	if(a == 1) printf("%2d既不是质数，也不是合数\n",a);
	if(a == 2) printf("%2d是质数\n",a);
	for(int i=2;i<a;i++){
		if(a % i == 0){
			printf("%2d不是质数\n",a);
			break;
		}
		else if(i == a-1){
			printf("%2d是质数\n",a);
		}
	}
}
int main(){
	int a;
	printf("输入一个数：\n");
	scanf("%d",&a);
	for(int k =1;k<a+1;k++) zhishu_chaxun(k);
	//for(int k =1;k<a+1;k++) zhishu_pangduan(k);
	return 0;
}
