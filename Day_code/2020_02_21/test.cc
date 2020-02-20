#include <iostream>
#include <stack>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    int n,l,c,x;
    int b[400000];//用来存储转化的二进制数
    stack<int> s;
    char a[100000];//用来存储输入的十六进制数
    cin >> n;
    while(n!=0)
    {
        l=0;
        cin >> a;
        for(int i=strlen(a)-1;i>=0;i--)
        {
            if(a[i]>='A'&&a[i]<='F')
            {
                x=a[i]-'A'+10;
            }
            else
            {
                x=a[i]-48;
            }
            for(int j = 0;j < 4;++j)
            {
                c=x%2;
                x=x/2;
                b[l++]=c;
            }   
        }
        int k=-1;
        int sum = 0;
        for(int i = 0;i<l;++i)
        {
            k++;
            sum+=b[i]*pow(2,k);
            if(k==2||i==l-1&&sum!=0)
            {
                k=-1;
                s.push(sum);
                sum=0;
            }
        }
        while(s.empty()!=true)
        {
            cout << s.top();
            s.pop();

        }
        cout<<endl;
        n--;

    }
    return 0;
}
