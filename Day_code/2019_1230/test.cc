#include <iostream>
#include <vector>
using namespace std;

vector<int> sumZero(int n) {
    vector<int> ret;
    if(n == 0)return ret;
    if (n % 2 == 1) {
        ret.push_back(0);
        n--;
    }
    while (n) {
        ret.push_back(n/2);
        ret.push_back(-n/2);
        n = n - 2;
    }
    return ret;
}

int main()
{
    int n = 10;
    vector<int> ret = sumZero(n);
    for(auto e : ret)
        cout<<e<<" ";
    cout<<endl;
    return 0;
}
