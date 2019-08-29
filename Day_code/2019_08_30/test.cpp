#include <iostream>
#include <vector>
using namespace std;

int MaxSum(vector<int> v,int n)
{
    int max = v[0];
    for(int i = 1; i < n; ++i)
    {
        if(v[i - 1] > 0)
        {
            v[i] += v[i - 1];
        }
        if(v[i] > max)
            max = v[i];
    }
    return max;
}

int main()
{
    int n = 0;
    while(cin >> n)
    {
        vector<int> v(n,0);
        for(int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }
    cout <<  MaxSum(v,n) <<endl;
    }
    return 0;
}
