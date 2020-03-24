#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int from = 0, to = 0;
    while(cin >> from >> to)
    {
        if(from < 1 || to > 80)
            continue;
        long count = 0;
        vector<long> v(82);
        v[0] = 0;
        v[1] = 1;
        v[2] = 1;
        for(int i = 3; i <= 80; ++i)
        {
            v[i] = v[i-1] + v[i-2];

        }
        for(int i = from; i <= to; ++i)
        {
            count += v[i];

        }
        cout << count << endl;

    }
    return 0;

}
