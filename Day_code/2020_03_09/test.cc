//不用加减乘除做加法
#include <iostream>
using namespace std;


class Solution 
{
public:
        int Add(int num1,int num2) 
        {
            while( num2 != 0  )
            {
                int sum = num1 ^ num2;
                int carray = (num1 & num2) << 1;
                num1 = sum;
                num2 = carray;
            }
            return num1;
        }
};

int main()
{
    int num1=0,num2=0;
    while(cin >> num1 >> num2)
    {
        Solution A;
        cout << A.Add(num1,num2) << endl;
    }
    return 0;
}
