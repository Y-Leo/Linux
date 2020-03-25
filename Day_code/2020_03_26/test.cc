#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n = 0;
    while(cin >> n)
    {
        vector<string> v(n + 1);
        for(int i = 0; i <= n; ++i)
            getline(cin,v[i]);
        for(int i = 0; i <= n; ++i)
        {
            int j = 0;
            int len = v[i].size();
            while(j <= len)
            {
                if(i < n && (v[i][j] == ',' || v[i][j] == ' '))
                {
                    cout << '"' << v[i] << '"' << ',' << ' ';
                    break;

                }
                else if(i == n && (v[i][j] == ',' || v[i][j] == ' '))
                {
                    cout << '"' << v[i] << '"' << endl;
                    break;

                }
                else if(j == len && i == n)
                {
                    cout << v[i] << endl;
                    break;

                }
                else if(j == len)
                {
                    cout << v[i] << ',' << ' ';
                    break;

                }
                ++j;

            }

        }

    }
    return 0;
}
