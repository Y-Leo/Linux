#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    for(int i = 0;i < 32;i++)
        printf("%d%d%d%d%d\n",i/16%2,i/8%2,i/4%2,i/2%2,i%2);
    return 0;

}
