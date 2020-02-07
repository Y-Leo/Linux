#include <stdio.h>

int main()
{
    int a,b;
    scanf("%d,%d",&a,&b);
    if(a>b)
    {
        a = b;
        b = a;
    }
    else
        a++;
    b++;
    printf("%d,%d",a,b);
    return 0;
}
