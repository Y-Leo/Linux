#include <iostream>
#include <vector>
using namespace std;

int movingCount(int threshold, int rows, int cols)
{
    vector<vector<int>> flag(rows+1); //记录是否已经走过
    for(int i=0;i<rows+1;++i){
        flag[i].resize(cols+1,0);

    }
    return helper(0, 0, rows, cols, flag, threshold);

}

int helper(int i, int j, int rows, int cols, vector<vector<int>>& flag, int threshold) {
    if (i < 0 || i >= rows || j < 0 || j >= cols || numSum(i) + numSum(j)  > threshold || flag[i][j] == 1)
        return 0;   
    flag[i][j] = 1;
    return helper(i - 1, j, rows, cols, flag, threshold)
        + helper(i + 1, j, rows, cols, flag, threshold)
        + helper(i, j - 1, rows, cols, flag, threshold)
        + helper(i, j + 1, rows, cols, flag, threshold)
        + 1;

}

int numSum(int i) {
    int sum = 0;
    do{
        sum += i%10;

    }while((i = i/10) > 0);
    return sum;

}

int main()
{
    return 0;
}
