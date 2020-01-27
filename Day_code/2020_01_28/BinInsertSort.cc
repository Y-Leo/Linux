#include <iostream>
#include <vector>
using namespace std;

//折半插入排序
//默认从小到大

void BinInsertSort(vector<int> &v,int n)
{
    if(n <= 1)
        return;
    else
    {
        int low,high,j = 0;
        for(int i = 1; i < n; ++i)
        {
            int value = v[i];  //待排序区间的第一个元素
            low = 0;   //已排序区间的第一个元素
            high = i - 1;  //已排序区间的最后一个元素

            //查找插入位置
            while(low <= high)
            {
                int mid = (low + high) / 2;
                if(v[mid] < value)
                    low = mid + 1;
                else
                    high = mid - 1;
            }

            //已经找到插入位置high+1处
            //搬移元素
            for(j = i - 1; j > high; j--)
                v[j + 1] = v[j];

            //搬移完成，进行插入
            v[j+1] = value;
        }
    }
}

int main()
{
    vector<int> v(10);
    int n =v.size();
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    BinInsertSort(v,n);
    for(auto e : v)
        cout << e <<" ";
    cout << endl;
    return 0;
}
