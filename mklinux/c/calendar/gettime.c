#include <stdio.h>
#include <time.h>
int main(){
    time_t now;
    struct tm *tm_now;
    time(&now);
    tm_now = localtime(&now);
    int year,month,day;
    year = tm_now->tm_year+1900;
    month = tm_now->tm_mon+1;
    day = tm_now->tm_mday;
    printf("%4d%4d%4d\n",year,month,day);
	return 0;
}
