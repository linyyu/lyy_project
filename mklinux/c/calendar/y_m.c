#include <stdio.h>
void y_m(int year){
	static int y_m[13] = {31,31,28,31,30,31,30,31,31,30,31,30,31};
	if (year%4==0 && year%100!=0){
		y_m[2] = 29;
	}
	else if (year%400 == 0) y_m[2] = 29;
}

