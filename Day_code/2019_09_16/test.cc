/*
#i#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
int n;
cin>>n;
vector<int> a(n);
int t,c[n-1];
for(int i=0;i<n;i++)
cin>>a[i];
for(int k=0;k<n-1;k++)    //总的循环（每次将最小两数和加入数组都重新进行排序和移动）
{
sort(a.begin(),a.end());
c[k]=a[0]+a[1];                        //将前两位的和赋给第一位，且后面的数前移一位
a[0]=c[k];
for(int i=1;i<n-1-k;i++)
a[i]=a[i+1];

}
int s=0;
for(int i=0;i<n-1;i++)
s+=c[i];
cout<<s<<endl;
return 0;

}
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],t,c[n-1];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];

    }
    for(int k=0;k<n-1;k++)    //总的循环（每次将最小两数和加入数组都重新进行排序和移动）
    {
        for(int i=0;i<n-1-k;i++)
        {
            for(int j=0;j<n-1-k-i;j++)
            {
                if(a[j]>a[j+1])                     //先进行从小到大的排序
                {
                    t=a[j];
                    a[j]=a[j+1];      
                    a[j+1]=t;

                }

            }

        }
        c[k]=a[0]+a[1];                        //将前两位的和赋给第一位，且后面的数前移一位
        a[0]=c[k];
        for(int i=1;i<n-1-k;i++)
        {
            a[i]=a[i+1];

        }

    }
    int s=0;
    for(int i=0;i<n-1;i++)
    {
        s+=c[i];

    }
    cout<<s;
    return 0;

}






