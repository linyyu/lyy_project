#include <stdio.h>

int main(){

    int age;
    float assets;
    char pet[30];

    printf("Enter your ages, assets ,and favorite pet.\n");
    printf("%d %f\n",&age,&assets);
    scanf("%s",pet);
    printf("%d $%.2f %s\n",age,assets,pet);


    return 0;
}


