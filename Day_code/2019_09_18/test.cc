#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int s=n%60;
    int h=n/3600;
    int m=n/60%60;
    cout<<h<<":"<<m<<":"<<s;
    return 0;

}



