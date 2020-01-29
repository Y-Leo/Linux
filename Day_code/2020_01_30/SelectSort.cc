#include <iostream>
#include <vector>
using namespace std;

//选择排序
//默认从小到大
void SelectSort(vector<int> &v,int n)
{
    if(n <= 1)
        return;
    else
    {
        for(int i = 0; i < n - 1; ++i)
        {
            int minIndex = i; //最小数的下标
            for(int j = i + 1; j < n; ++j)
                if(v[j] < v[minIndex])
                    minIndex = j;

            int tmp = v[i];
            v[i] = v[minIndex];
            v[minIndex] = tmp;
        }
    }         
}
int main()                                                                                                                       
{                                                                                                                                                            
    vector<int> v(10);                                                                                                                                       
    int n = v.size();                                                                                                            
    for(int i = 0; i < n; ++i)                                                                                                   
        cin >> v[i];                                                                                                             
    SelectSort(v,n);                           
    for(auto e : v)                            
        cout << e <<" ";                       
    cout << endl;                              
    return 0;                                  
}
