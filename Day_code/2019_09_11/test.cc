#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v.begin(),v.end());
    cout << v[n-1] << endl;
    cout << v[0] << endl;
    int ret = 0;
    for(int i = 0; i < n; ++i)
        ret += v[i];
    cout << ret << endl;
    return 0;

}
