#include <iostream>
#include <string>
using namespace std;

int a[10000000];
int main()
{
    int n, k = 0;
    cin >> n;
    if(!n)
        cout << n;
    else
    {
        while(n)
        {
            a[k++] = n % 16;
            n /= 16;

        }
        for(int i = k - 1; i >= 0; i--)
        {
            switch(a[i])
            {
                case 10 : cout << "A"; break;
                case 11 : cout << "B"; break;
                case 12 : cout << "C"; break;
                case 13 : cout << "D"; break;
                case 14 : cout << "E"; break;
                case 15 : cout << "F"; break;
                default : cout << a[i]; break;

            }

        }
        cout << endl;

    }
    return 0;

}
