/*
从四个人的说法中可以分别看出，每个人的一句话都对应了一个人是凶手或者不是凶手。我们可以通过定义一个变量killer，for语句在字符a和d循环，for语句中用||嵌套四个条件，当条件有三个满足的时候，输出killer。
  */
#include<stdio.h>
int main(){
		char killer;
		for(killer='a'; killer<='d'; killer++){
			if((killer!='a') + (killer=='c') + (killer=='d') + (killer!='d') == 3){
				printf("凶手是%c\n",killer);
				break;
			}
		}
		return 0;
}
