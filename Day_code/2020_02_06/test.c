#include <stdio.h>

int f(int n)
{
    if(n) return f(n - 1) + n;
    else return n;
}

int main()
{
    int n = 4;
    printf("%d\n",f(n));
    return 0;
}
