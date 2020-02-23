#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() 
{
    int r = 0;
    cin >> r;
    const double PI = atan(1.0)*4;
    printf("%.7f",PI*r*r);
    return 0;

}
