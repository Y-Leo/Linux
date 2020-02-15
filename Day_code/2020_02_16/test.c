#include <stdio.h>

int  NumberOf1(int n) {
    int count=0;
    while(n)
    {
        ++count;
        n=n&(n-1);

    }
    return count;
}

int main()
{
    int n = 100;
    printf("%d\n",NumberOf1(n));
    return 0;
}
