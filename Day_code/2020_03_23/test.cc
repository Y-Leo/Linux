#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    vector<int> v(1000001);
    v[0] = 1;
    v[1] = 1;
    for (int i = 2; i < 1000001; ++i)
    {
        v[i] = (v[i - 1] + v[i - 2]) % 1000000;

    }
    while (cin >> n)
    {
        if (n < 29)
            cout << v[n] << endl;
        else
            cout << setfill('0') << setw(6) << v[n] << endl;

    }
    return 0;

}
