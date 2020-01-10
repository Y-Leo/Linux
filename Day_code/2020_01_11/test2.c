#include <stdio.h>

int main()
{
    int i,j,a[2][3];
    for(i=0;i<6;i++) a[i][i]=i;
    for(i=0;i<2;i++) for(j=0;j<3;j++) 
        printf("a[%d][%d] = %d\n",i,j,a[i][j]);
    
    int k = -1;
    k = k % 7;
    printf("k = %d\n",k);
    return 0;
}
