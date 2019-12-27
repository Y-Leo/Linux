#include<iostream>
#include<string>
using namespace std;

bool match(string& str, string& pattern)
{
    if (pattern[0] == 0 && str[0] == 0)
    {
        return true;
    }

    if (pattern[0] != 0 && pattern[1] == '*')
    {
        if (match(str, pattern + 2))
            return true;
    }

    if ((pattern[0] == '.' && str[0]) || str[0] == pattern[0])
    {
        if (match(str + 1, pattern + 1))
            return true;
        if (pattern[1] == '*' && match(str + 1, pattern))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string str = "abcdeded";
    string pattern = "a.*d";
    bool ret = match(str,pattern);
    cout << ret <<endl;
    return 0;
}
