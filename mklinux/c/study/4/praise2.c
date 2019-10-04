#include <stdio.h>
#include <string.h>
#define PRAISE "you're an extraordinary being."
int main(){
        char name[40];
        printf("What's your name?\n");
        scanf("%s",name);
        printf("Hello, %s. %s\n",name,PRAISE);
        printf("Your name of %d letters occuples %d memory cells.\n",strlen(name),sizeof name);
        printf("The phrase of praise has %d letters ",strlen(PRAISE));
        printf("and occupies %d memory cells.\n",sizeof PRAISE);

        return 0;
}


