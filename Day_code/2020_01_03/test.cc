#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> ret;
    for(int i = 0;i < nums.size(); ++i)
    {
        for(int j = i+1;j < nums.size(); ++j)
        {
            if(nums[i]+nums[j] == target)
            {
                ret.push_back(i);
                ret.push_back(j);
            }
        }
    }
    return ret;
}

int main()
{
   vector<int> v{2,7,11,15};
   int n = 9;
   vector<int> ret = twoSum(v,n);
   cout<<ret[0]<<" "<<ret[1]<<endl;
   return 0;
}
