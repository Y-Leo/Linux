//问题：找假币
//一堆硬币中有一个较轻的假币，最快用天平几次找出来

/*举几个例子就能想到最快的方法是分成三份：
 *比较其中的两份，如果不相等则假币在轻的那份，如果相等则假币在第三份，直接n%3
 *接下来考虑不能均分的情况：
 *因为是分3份，所以只可能多余1或两个
 *我们考虑最差的情况，假币在最多的一份里，最多的那份为n%3+1
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if (0 == n)
            break;
        int count = 0;
        while (n >= 2)
        {
            if (n % 3)
                n = n / 3 + 1;
            else
                n = n / 3;
            ++count;

        }
        cout << count << endl;

    }
    return 0;

}
