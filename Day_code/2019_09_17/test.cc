#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

int main() 
{
    string str1, str2;
    cin >> str1;
    cin >> str2;
    if (str1.size() == str2.size()) 
    {
        if (str1 != str2) 
        {
            transform(str1.begin(), str1.end(), str1.begin(),::toupper);    //转换大小写
            transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
            if (str1 == str2) 
                cout << "3" << endl;
            else 
                cout << "4" << endl;

        }
        else 
            cout << "2" << endl;

    }
    else 
        cout << "1" << endl;
    system("pause");
    return 0;

}



