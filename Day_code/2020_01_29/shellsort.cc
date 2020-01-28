#include <iostream>
#include <vector>
using namespace std;

void shellsort(vector<int> &v,int len)
{
    if(len <= 1)
        return;
    else
    {
        int step = len / 2;
        while(step >= 1)
        {
            for(int i= step; i < len; ++i)
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
    int len = v.size();
    for(int i = 0; i < len; ++i)
        cin >> v[i];
    shellsort(v,len);
    for(auto e : v)
        cout << e <<" ";
    cout << endl;
    return 0;
}
