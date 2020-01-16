#include <stdio.h>
#include <string.h>

int main()
{
    char s[] = "abcdefgh",*p = s;
    p += 3;
    printf("%d\n",strlen(strcpy(p,"ABCD")));
    return 0;
}
