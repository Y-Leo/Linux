#include <stdio.h>

int main()
{
    int year = 1;
    int *p = &year;

    *p += 1;
    printf("%d\n",year);

    (*p)++;
    printf("%d\n",year);

    ++(*p);
    printf("%d\n",year);

    *p++;
    printf("%d\n",year);
    return 0;
}
