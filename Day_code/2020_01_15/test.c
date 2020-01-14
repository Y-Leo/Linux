#include <stdio.h>

int func(int a)
{
    int b;
    switch(a)
    {
        case 1 : b = 30;
        case 2 : b = 20;
        case 3 : b = 16; break;
        default : b = 0;
    }
    return b;
}

int func2()
{
    int b[2][5] = {0,1,2,3,4,5,6,7,8,9};
    int i = 1,j = 4;
    printf("b[i][j] = %d\n",b[i][j]);
    printf("b[i][j] = %d\n",*(b[i]+j));
    printf("b[i][j] = %d\n",*(*b+i)+j);
    printf("b[i][j] = %d\n",(*(b+i))[j]);
}

int main()
{
    func2();
    //printf("b = %d\n",func(1));
    return 0;
}
