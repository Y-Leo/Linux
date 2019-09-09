#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];

    }
    int a = 0;
    while(cin >> a)
    {
        for(int i = 0; i < n; ++i)
        {
            if(a == v[i])
            {
                cout << i+1 << endl;
                break;

            }       
            if(i == n-1)
                cout << "-1" << endl;

        }

    }
    return 0;

}
