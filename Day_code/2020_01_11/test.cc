#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    k = k % nums.size();
    reverse(nums.begin(),nums.end()-k);
    reverse(nums.begin()+(nums.size()-k),nums.end());
    reverse(nums.begin(),nums.end());
    for(auto e : nums)
    {
        cout<<e<<"  ";
    }
    cout<<endl;
    return 0;
}
