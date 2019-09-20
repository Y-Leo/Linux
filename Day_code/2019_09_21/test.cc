#include<iostream>
using namespace std;

int main()
{
    int v1,v2,t,s,l;
    cin>>v1>>v2>>t>>s>>l;
    int num=0,s1=0,s2=0;
    while(1)
    {
        if(s1>=l&&s2>=l)
        {
            cout<<"D"<<endl;
            cout<<num;
            break;
        }
        else if(s1>=l)
        {
            cout<<"R"<<endl;
            cout<<num;
            break;
        }
        else if(s2>=l)
        {
            cout<<"T"<<endl;
            cout<<num;
            break;
        }
        if(s1-s2>=t)
        {
            for(int i=0;i<s;i++)
            {
                num++;
                s2+=v2;
                if(s2>=l)
                {
                    cout<<"T"<<endl;
                    cout<<num;
                }
            }
        }
        else
        {
            num++;
            s1+=v1;
            s2+=v2;

        }

    }
    return 0;
}


