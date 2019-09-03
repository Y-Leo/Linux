#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char s[8];
    while(cin >> s)
    {
        int len = strlen(s);
        long long int m = 0, n = 16;
        for(int i = 0; i < len; ++i)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                m = m * n + (s[i] - '0');

            }
            else
            {
                m = m * n + (s[i] - 'A' + 10);

            }

        }
        cout << m;

    }
    return 0;

}
