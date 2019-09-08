#include <iostream>
using namespace std;
#define N 34 

int main()
{
    int n,a[N][N],i,j;
    cin >> n;

    //初始化二维数组
    for(i=0;i<n;i++)
    {
        //每行第一个和最后一个置为1
        a[i][0]=a[i][i]=1;
        //每行中间的数初始化
        for(j=1;j<i;j++)
            a[i][j]=a[i-1][j-1]+a[i-1][j];
    }

    //打印杨辉三角
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    } 
    return 0; 
} 



