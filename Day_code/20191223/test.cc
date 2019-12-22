#include <iostream>
#include <vector>
using namespace std;

vector<int> multiply(const vector<int>& A) {
    int len = A.size();
    if(len < 1)
        return A;
    vector<int> result(len, 0);
    result[0] = 1;
    for(int i = 1; i < len; i++)
        result[i] = result[i - 1] * A[i - 1];
    int temp = 1;
    for(int j = len - 2; j >= 0; j--)
    {
        temp *= A[j + 1];
        result[j] *= temp;

    }
    return result;

}

int main()
{
    return 0;
}
