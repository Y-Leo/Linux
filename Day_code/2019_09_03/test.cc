#include <iostream>
using namespace std;

int fib(int n)
{
    int v[2] = {0,1};
    if(n < 2)
        return v[n]%10007;
    int f1 = 1,f2 = 1, f3 = 1;
    for(int i = 3;i<=n;++i)
    {
        f3=(f1%10007 + f2%10007)%10007;
        f1=f2;
        f2=f3;

    }
    return f3;

}

int main() 
{
    int n = 0;
    cin >> n;
    cout << fib(n) <<endl;
    return 0;

}
