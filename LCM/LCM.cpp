#include<iostream>
using  namespace std;

int LCM(int a,int b)
{
   int Max= a>b ? a:b;
   int Min= a<b ? a:b;

   for(int i=Max;i<=a*b;++i)
   {
     if(i%a==0&&i%b==0)
     {
       return i;
     }
   }
}
int main()
{
  int A=0,B=0;
  cin>>A>>B;
  cout<<LCM(A,B)<<endl;

  return 0;
}
