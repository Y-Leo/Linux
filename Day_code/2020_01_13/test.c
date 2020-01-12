#include <stdio.h>

int main()
{
    int  i = 0,a = 0;
    while(i < 20)
    {
        for(;;)
        {
            if(0 == (i % 10))break;
            else i--;
        }
        i += 11, a += i;
    }
    printf("a = %d\n",a);
    return 0;
}
