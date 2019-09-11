#include <iostream>
using namespace std;

int main()
{
    char a[26][26];
    int n,m;
    cin>>n>>m;
    for(int j=0;j<m;j++)
    {
        a[0][j]='A'+j;           //先表示出第一行的各元素

    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i<=j)
                a[i][j]=a[i-1][j]-1;        //上一个元素-1
            if(i>j)
                a[i][j]=a[i-1][j]+1;       //上一个元素+1

        }

    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<a[i][j];

        }
        cout<<endl;

    }
    return 0;

}



