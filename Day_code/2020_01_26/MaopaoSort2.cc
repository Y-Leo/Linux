#include <iostream>
#include <vector>
using namespace std;

//升级版的冒泡排序
//默认由小到大

void MaopaoSort2(vector<int> &v,int n)
{
    if(n <= 1)
        return;
    else
    {
        for(int i = 0; i < n ; ++i)  //第一层循环控制排序次数，有n个数则进行n次排序
        {
            bool flag = false;
            for(int j = 0; j < n - i - 1; ++j)
            {
                if(v[j] > v[j+1])
                {
                    flag = true;
                    int temp = v[j];
                    v[j] = v[j+1];
                    v[j+1] = temp;
                }
            }
            if(!flag)
                break;
        }
    }
}

int main()
{
    vector<int> v(10);
    int n = v.size();
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    MaopaoSort2(v,n);
    for(auto e : v)
        cout << e <<" ";
    cout << endl;
    return 0;
}
