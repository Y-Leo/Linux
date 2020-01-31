#include <stdio.h>

int main()
{
    char str[] = "ABCD", *p = str;
    printf("%d\n",*(p+4));
    return 0;
}
