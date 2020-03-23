#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s,t;
    while(cin >> s >> t)
    {
        if(s == "" || t == "" || s.size() < t.size())
            continue;
        int count = 0;
        int start_s = 0;
        while(start_s != s.size())
        {
            if(s.substr(start_s,t.size()) == t)
            {
                start_s += t.size();
                count++;

            }
            else
            {
                start_s++;

            }

        }
        cout << count << endl;

    }
    return 0;

}
