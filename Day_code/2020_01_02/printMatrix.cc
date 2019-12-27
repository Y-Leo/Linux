#include <iostream>
#include<vector>
using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> ret;

    //输入的二维数组非法，返回空的数组
        if (row == 0 || col == 0)  return ret;
    //四个变量，分别代表四个边界，左，右，顶，底
    int left = 0,right = col - 1,top = 0,bottom = row -1;
    //循环把遍历的结果放入ret中
    //4个步骤完成
    while(left <= right && top <= bottom)
    {
        //1、左到右
        for(int i = left;i <= right; ++i)  ret.push_back(matrix[top][i]);
        //2、顶到底
        for(int i = top + 1;i <= bottom; ++i) ret.push_back(matrix[i][right]);
        //3、右到左
        if(bottom != top)
            for(int i = right - 1; i >= left; --i) ret.push_back(matrix[bottom][i]);
        //4、底到顶
        if(right != left)
            for(int i = bottom - 1; i > top; --i) ret.push_back(matrix[i][left]);
        left++,top++,right--,bottom--;
    }
    return ret;
}

int main()
{
    vector<vector<int>> v = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<int> result = printMatrix(v);
    for(auto e : result)
    {
        cout<<e<<" ";
    }
    cout<<endl;
    return 0;
}

