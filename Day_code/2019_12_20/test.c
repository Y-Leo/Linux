#include <iostream>
using namespace std;

int LastRemaining_Solution(int n, int m)
{
    if(n==0) return -1;
    int s=0;
    for(int i=2;i<=n;i++){
        s=(s+m)%i;

    }
    return s;

}

int main()
{
    int n = 10;
    int m = 20;
    cout << LastRemaining_Solution(n,m)<<endl;
    return 0;
}
