#include<iostream>
#include<string.h>
using namespace std;
int a[35][35];
int b[35][35];
int c[35][35];
void com(int n,int m);

int main()
{
    int n,m;
    cin >> n >> m;//n是阶数，m是幂 
    int i,j;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    for(i = 0;i < n;i ++)
    {
        for(j = 0;j < n;j ++)
        {
            cin >> a[i][j];
            b[i][j] = a[i][j];

        }

    }
    if(m)   
        com(n,m);
    else
    {
        memset(b,0,sizeof(b));//只能用来初始化0，其他数字不行
        for(i = 0;i < n;i ++)
            b[i][i] = 1; 
        for(i = 0;i < n;i ++)
        {
            for(j = 0;j < n;j ++)
            {
                cout << b[i][j] << " ";

            }
            cout << endl;

        } 

    }

    return 0;

}

void com(int n,int m)
{
    int i,j,k,x;
    j = 0;


    for(x = 0;x < m - 1;x ++)
    {
        for(i = 0;i < n;i ++)
        {
            for(j = 0;j < n;j ++)
            {
                for(k = 0;k < n;k ++)
                {
                    c[i][j] +=  a[i][k] * b[k][j];

                }

            }

        } 
        for(int y = 0;y < n;y ++)
        {
            for(int t = 0;t < n;t ++)
            {
                b[y][t] = c[y][t];


            }

        }
        memset(c,0,sizeof(c));

    } 


    for(i = 0;i < n;i ++)
    {
        for(j = 0;j < n;j ++)
        {
            cout << b[i][j] << " ";//这里每个数字后面都有空格，但是有的题目并不是这样，有的题目每行的最后一个数字后面是不要空格的，遇到这种情况，题目上也没有具体说明的，就要去问！ 

        }
        cout << endl;

    }



}


