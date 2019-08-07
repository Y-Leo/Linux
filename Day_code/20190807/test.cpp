#include<iostream>
using namespace std;
//汽水瓶:
int main()
{
  int n=0;
  while(cin>>n)
  {
    if(n<0)
      return 0;
    cout<<n/2<<endl;
  }
  return 0;
}
