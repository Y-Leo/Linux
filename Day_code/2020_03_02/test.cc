#include <iostream>
using namespace std;

int main()
{
    double n = 0, r = 0;
    while(cin >> n >> r)
    {
        int c = 2 * 3.14 * r;
        if(c > n)
            cout << "Yes" << endl;
        else
            cout<< "No" << endl;
    }
    return 0;
}
