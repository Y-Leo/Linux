#include <stdio.h>

int func(int i,int j)
{
    if(i <= 0 || j <= 0)
    return 1;
    return 2 * func(i - 3, j / 2);
}

int main()
{
    printf("%d\n",func(15,20));
    return 0;
}
