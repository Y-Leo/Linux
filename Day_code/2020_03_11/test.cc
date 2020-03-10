#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    while(getline(cin,str))
    {
        if(0 == str.size())
            break;
        string ret;
        for(size_t i = 0; i < str.size(); ++i)
        {
            if(str[i] == ' ')ret += ' ';
            else if(str[i] == 'A')ret += 'V';
            else if(str[i] == 'B')ret += 'W';
            else if(str[i] == 'C')ret += 'X';
            else if(str[i] == 'D')ret += 'Y';
            else if(str[i] == 'E')ret += 'Z';
            else
                ret += str[i] - 5;
        }
        cout << ret << endl;
    }
    return 0;
}
