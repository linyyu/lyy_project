#include <stdio.h>
 
int main()
{
    int n1, n2, minMultiple;
    printf("输入两个正整数: ");
    scanf("%d %d", &n1, &n2);
 
    // 判断两数较大的值，并赋值给 minMultiple
    minMultiple = (n1>n2) ? n1 : n2;
 
    // 条件为 true
    while(1)
    {
        if( minMultiple%n1==0 && minMultiple%n2==0 )
        {
            printf("%d 和 %d 的最小公倍数为 %d", n1, n2,minMultiple);
            break;
        }
        ++minMultiple;
    }
    return 0;
}
