#include <iostream>
using namespace std;


int main()
{
    int a = 0;
    a = 'A' + 1.6;
    cout<< a <<endl;

    cout<<endl;
    int x = 10;
    int y = 10;
    x = y = ++y;
    cout<<x<<endl;
    cout<<y<<endl;
    return 0;
}
