#include <stdio.h>
//循环法
int zzxj(int max,int min){
	int tmp;
	tmp = max - min;
	while(tmp != min){
		if(tmp > min){
			tmp = tmp - min;
		}
		else{
			int k = tmp;
			tmp = min - tmp;
			min = k;
		}
	}
	return tmp;
}

//递归法
int zzxj1(int max,int min){
	int tmp;
	tmp = max - min;
	if(tmp == min) return tmp;
	else if(tmp > min){
			max = tmp;
			return zzxj1(max,min);
	}
	else{
		max = min;
		min = tmp;
		return zzxj1(max,min);
	}
}

int main(){
	int a,b;
	int max,min;
	printf("输入两个数：\n");
	scanf("%d %d",&a,&b);
	if(a>b){
		max = a;
		min = b;
	}
	else{
		max = b;
		min = a;
	}
	printf("循环法：%2d\n",zzxj(max,min));	
	printf("递归法：%2d\n",zzxj1(max,min));	
}
