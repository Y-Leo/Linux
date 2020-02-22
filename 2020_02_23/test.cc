#include<iostream>
using namespace std;

int main()
{
    int y=0;
    while(cin>>y)
    {
        if(y%400==0||(y%4==0&&y%100!=0))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;

    }
    return 0;

}
