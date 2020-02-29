#include <iostream>
using namespace std;

int main()
{
    union AB
    {
        int a;
        int b;
    }c;
    c.a = 1;
    if(1 == c.b)
        cout << "当前计算机为小端机器" << endl;
    else
        cout << "当前计算机为大端机器" << endl;

    return 0;
}
