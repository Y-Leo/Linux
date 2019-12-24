#include <iostream>
#include <vector>
using namespace std;

vector<int> median;
void Insert(int num)
{
    vector<int>::iterator pos=upper_bound(median.begin(),median.end(),num);
    median.insert(pos,num);

}

double GetMedian()
{
    if(median.size()==0) return 0.0;
    int pos=median.size()/2;
    if(median.size()%2==1){
        return median[pos];

    }
    return (median[pos-1]+median[pos])/2.0;

}

int main()
{
    return 0;
}
