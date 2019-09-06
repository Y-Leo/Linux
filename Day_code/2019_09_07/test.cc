#include<iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 10000;i <= 999999;++i) 
        {
            if (i <= 99999)
            {
                int temp = i;
                int a, b, c, d, e;
                a = temp % 10;
                b = temp / 10 % 10;
                d = temp / 1000 % 10;
                c = temp / 100 % 10;
                e = temp / 10000;
                if (a == e&&b == d&&a + b + c + d + e == n)
                    cout << i << endl;

            }
            else 
            {
                int temp = i;
                int a, b, c, d, e, f;
                a = temp % 10;
                b = temp / 10 % 10;
                c = temp / 100 % 10;
                d = temp / 1000 % 10;
                e = temp / 10000 % 10;
                f = temp / 100000;
                if (a == f&&b == e&&c == d&&a + b + c + d + e + f == n)
                    cout << i << endl;

            }

        }

    }
    return 0;

}


