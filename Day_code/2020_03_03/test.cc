//青蛙跳台阶&&变态青蛙跳台阶
#include <iostream>
using namespace std;

//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
//f(n) = f(n-1) + f(n-2)
int JumpFloorI(int number)
{
    if(number < 3)
        return number;
    return JumpFloorI(number - 1) + JumpFloorI(number - 2);
}


//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
//f(n)   = f(n-1) + f(n-2) + f(n-3) + ... + f(0);
//f(n-1) =          f(n-2) + f(n-3) + ... + f(0);
//简化得到:f(n) = 2 * f(n-1)
int JumpFloorII(int number)
{
    if(number < 3)
        return number;
    return 2 * JumpFloorI(number - 1);
}

int main()
{
    int number = 0;
    while(cin >> number)
    {
        cout << JumpFloorI(number) << endl;
    }
    return 0;
}
