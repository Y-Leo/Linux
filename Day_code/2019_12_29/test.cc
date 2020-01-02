#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool IsContinuous( vector<int> numbers  ) 
{
    //牌数不足五张则返回错误
    if(numbers.size()<5) return false;
    //对五张牌排序
    sort(numbers.begin(),numbers.end());

    int change=0,cnt=0;
    for(int i=1;i<5;i++) {
        if(!numbers[i-1]) change++;
        if(numbers[i-1]) cnt+=numbers[i]-numbers[i-1]-1;
        if(numbers[i-1]&&numbers[i]==numbers[i-1]) return false;
    }
    return change>=cnt;
}

int main()
{
    vector<int> v = {2,3,6,0,0};
    if(IsContinuous(v))
        cout<<"Luckly"<<endl;
    else
        cout<<"Sorry"<<endl;
    vector<int> v1 = {2,3,6,7,0};
    if(IsContinuous(v1))
        cout<<"Luckly"<<endl;
    else
        cout<<"Sorry"<<endl;
    return 0;
}

