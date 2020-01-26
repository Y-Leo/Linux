#include <iostream>
#include <vector>
using namespace std;

//直接插入排序
//默认为从小到大

void InsertSort(vector<int> &v,int n)
{
    if(n <= 1)
        return;
    else
    {
        for(int i = 1; i < n; ++i)
        {
            int value = v[i]; //当前待排序元素
            int j = i - 1;  //已排序区间的最后一个元素
            for(; j >= 0; j--) //与已排序元素从后往前依次比较，查找插入位置
            {
                if(v[j] > value)
                    v[j+1] = v[j];
                else
                    break;  //此时已经找到插入位置
            }
            v[j+1] = value;
        }
    }
}

int main()
{
    vector<int> v(10);
    int n = v.size();
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    InsertSort(v,n);
    for(auto e : v)
        cout << e <<" ";
    cout << endl;
    return 0;
}
