#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool isPrime(int n)
{
    if(n==2||n==3)  
        return true;
    if(n%6!=1&&n%6!=5)  
        return false;
    for(int i=5;i<=floor(sqrt(n));i+=6)
        if(n%i==0||n%(i+2)==0)  
            return false;
    return true;
}

int main()
{
    int n = 0;
    while(cin >> n)
    {
        if(isPrime(n) || 0 == n || 1 == n)
        {
            cout << n << " " << "=" << " " << n << endl;
            continue;
        }
        vector<int> v;
        int sq = sqrt(n)+1;
        int temp = n;
        for(int i = 2; i <= sq; ++i)
        {
            if(0 == n % i)
            {
                while(0 == n % i)
                {
                    v.push_back(i);
                    n /= i;
                }
                if(isPrime(n) && n != 1)
                {
                    v.push_back(n);
                    break;
                }
            }
        }
        int size = v.size();
        cout<<temp<<" "<<"="<<" ";
        for(int i = 0; i < size; ++i)
        {
            cout<<v[i];
            if(i != size - 1)
                cout<<" "<<"*"<<" ";
        }
        cout << endl;
    }
    return 0;
}
