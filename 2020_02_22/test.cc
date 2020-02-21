#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int main()
{
    int n=0;
    while(cin>>n)
    {
        vector<int> v(n);
        for(int i=0;i<n;++i)
        {
            cin>>v[i];

        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;++i)
        {
            cout<<v[i];
            if(v.begin()+i!=v.end())
                cout<<" ";

        }

    }
    return 0;

}
