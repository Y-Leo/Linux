#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
        /**
         *      *  奇数位上都是奇数或者偶数位上都是偶数
         *           *  输入：数组arr，长度大于2
         *                *  len：arr的长度
         *                     *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
         *                          */
        void oddInOddEvenInEven(vector<int>& arr, int len)
        {

            for(int i = 0; i < len; i+=2)
            {
                for(int j = 1; j < len; j+=2)
                {
                    if(arr[i] & 1 == 0)
                    {
                        break;
                    }
                    if(arr[j] & 1 == 1)
                    {
                        continue;
                    }
                    swap(arr[i],arr[j]);
                }
            }
        }
/*
            int i = 0, j = 1;
            while (i<len && j<len)
            {
                if ((arr[i] & 1) == 0) //偶数位上寻找非偶数，否则跳过
                {
                    i += 2;
                    continue;
                }
                if ((arr[j] & 1) == 1) //奇数位上寻找非奇数，否则跳过
                {
                    j += 2;
                    continue;
                }
                swap(arr[i], arr[j]); 
                i += 2;
                j += 2;
            }
  */
};

int main()
{
    Solution A;
    int len = 0;
    cin >> len;
    vector<int> v(len);
    for(int i = 0; i < len; ++i)
    {
        cin >> v[i];
    }
    A.oddInOddEvenInEven(v,len);

    for(auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
