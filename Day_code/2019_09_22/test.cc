#include<iostream>
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;

    for(int i=m; i<=n; i++)
    {
        cout<<i<<"=";
        int p=i;
        int t=2;
        int flag=0;
        while(p!=1)
        {
            while(p%t==0)
            {
                if(flag==0)
                {
                    cout<<t;
                    flag=1;

                }
                else
                    cout<<"*"<<t;
                p/=t;

            }
            t++;

        }
        cout<<endl;

    }
    return 0;

}



