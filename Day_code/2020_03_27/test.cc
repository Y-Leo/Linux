#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 0;
    while(cin >> n)
    {
        vector<int> v(95);
        v[0] = 0;
        v[1] = 1;
        v[2] = 2;
        for(int i = 3; i <= 90; ++i)
            v[i] = v[i-1] + v[i-2];
        cout << v[n] << endl;
    }
}
