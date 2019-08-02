#include<iostream>
using  namespace std;
#include<vector>
#include<algorithm>

void MinNumbers(vector<int>& v,int n)
{
   sort(v.begin(),v.end());


   for(int i=0;i<n;++i)
   {
     cout<<v[i];
   }
   cout<<endl;
}

int main()
{
  int n;
  vector<int> v(10);
  cin>>n;
  for(int i=0;i<10;i++)
  {
    cin>>v[i];
  }
  
 MinNumbers(v,n);
  return 0;
}
