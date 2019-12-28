#include <iostream>
#include <vector>
using namespace std;

int game(vector<int>& guess, vector<int>& answer) {
    int ret = 0;
    if(guess.empty() || answer.empty())
        return 0;
    for(int i = 0; i < 3; ++i)
    {
        if(guess[i] == answer[i])
            ret++;
    }
    return ret;
}

int main()
{
    vector<int> v1{1,2,3};
    vector<int> v2 = {3,2,1};
    cout<<game(v1,v2)<<endl;
    return 0;
}
