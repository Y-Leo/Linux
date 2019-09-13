#include <iostream>
#include <vector>
using namespace std; 

int main() 
{
    int n;
    cin>>n; 
    vector<int> v,a;
    v.push_back(1); 
    for(int i=2;i<=n;i++)
    {
        int s,r=0;
        a.clear();
        a.reserve(v.size()); 
        for(int j=0,size=v.size();j<size;j++)
        {
            s=i*v[j]+r;
            r=s/10;                 
            a.push_back(s%10);

        }
        while(r)
        {
            a.push_back(r%10);
            r/=10;

        }
        v.assign(a.begin(),a.end());

    }
    for(int j=v.size()-1;j>=0;j--)  
        cout<<v[j];
    return 0;

}



