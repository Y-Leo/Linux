/*
 *正数数组和的的最小不可能值
 *给一个正数数组，非空
 *求它的非空子集的和，最小和为min，最大和为max
 *以min , max为区间，如果区间之内的数不在arr中，则找出最小的那个输出
 *如果都在区间中，则输出max+1
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int getFirstUnFormedNum(vector<int> arr, int len) {
            int sum = 0, min = arr[0];
            for (int i = 0; i < len; ++i)
            {
                sum += arr[i];
                if (arr[i] < min)
                    min = arr[i];
            }
            vector<int> dp(sum + 1, 0);
            for (int i = 0; i < len; ++i)
            {
                for (int j = sum; j >= arr[i]; --j)
                {
                    if (dp[j - arr[i]] + arr[i] > dp[j])
                    {
                        dp[j] = dp[j - arr[i]] + arr[i];
                    }
                }
            }

            for (int i = min; i <= sum; ++i)
            {
                if (i != dp[i])
                    return i;
            }
            return sum + 1;
        }
};

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        Solution s;
        cout << s.getFirstUnFormedNum(a, n) << endl;
    }
    return 0;
}
