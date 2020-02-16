#include <iostream>
#include <vector>
using namespace std;
//冒泡排序
//默认为从小到大

void MaopaoSort(vector<int> &v)
{
    if(v.empty())
        return;
    int n = v.size();
    for(int i = 0; i < n; ++i)  //控制循环次数,有n个元素，则进行n次排序
    {
        for(int j = 0; j < n - i -1; ++j)   //控制每一趟排序，然后进行元素交换
        {
            if(v[j] > v[j + 1]) //如果满足交换条件则交换
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }   
}

int main()
{
   vector<int> v(10);
   int n = v.size();
   for(int i = 0; i <  n; ++i)
       cin >> v[i];
   MaopaoSort(v);
   for(auto e : v)
      cout << e <<" ";
   cout << endl;
   return 0;
}
