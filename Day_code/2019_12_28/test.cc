#include <iostream>
#include <limits.h>
using namespace std;

int reverse(int x) {
    int ret = 0;
    while (x != 0) {
        //tmp为余数，每次取余
            int tmp = x % 10;
        x /= 10;
        if (ret > INT_MAX/10 || (ret == INT_MAX / 10 && tmp > 7)) return 0;
        if (ret < INT_MIN/10 || (ret == INT_MIN / 10 && tmp < -8)) return 0;
        ret = ret * 10 + tmp;
    }
    return ret;
}

int main()
{
    int n = 12345;
    int ret  = reverse(n);
    cout<<ret<<endl;
    int m = -1230;
    ret  = reverse(m);
    cout<<ret<<endl;
    return 0;
}
