#include <iostream>
#include <vector>
using namespace std;

int findNumbers(vector<int>& nums) {
    int ret = 0;
    if(nums.empty())
        return 0;
    for(int i = 0;i < nums.size(); ++i)
    {
        int tmp = 0;
        if(0 == nums[i])
            continue;
        while(nums[i])
        {
            nums[i]/=10;
            tmp++;
        }
        if(0 == tmp % 2)
            ret++;
    }
    return ret;
}

int main()
{
    vector<int> v{12,0,33,1234,34567,1};
    cout<<findNumbers(v)<<endl;
    return 0;
}
