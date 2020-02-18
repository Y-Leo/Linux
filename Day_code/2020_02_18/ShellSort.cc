#include <iostream>
#include <vector>
using namespace std;

// 希尔排序
// 默认为从小到大

void ShellSort(vector<int> &v,int len)
{
    if(len <= 1)
        return;
    else
    {
        int step = len / 2;
        while(step >= 1)
        {
            for(int i = step; i < len; ++i)
            {
                int value = v[i];
                int j = i - step;
                for(; j >= 0; j -= step)
                {
                    if(value < v[j])
                        v[j + step] = v[j];
                    else
                        break;
                }
                v[j + step] = value;
            }
            step /= 2;
        }
    }
}

int main()
{
    vector<int> v(10);
    int n = v.size();
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    ShellSort(v,n);
    for(auto e : v)
        cout << e <<" ";
    cout << endl;
    return 0;
}
