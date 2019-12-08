#include <iostream>
using namespace std;

bool hasPathOne(char* matrix, int i, int j, int rows, int cols, char* str, int k, int *flag){
    int index = i*cols + j;
    if (i < 0 || j < 0 || i >= rows || j >= cols || flag[index] == 1 || matrix[index] != str[k]) return false;
    if (k == strlen(str)-1) {return true;}
    flag[index] = 1;
    if( hasPathOne(matrix, i-1, j, rows, cols, str, k+1, flag)||
            hasPathOne(matrix, i+1, j, rows, cols, str, k+1, flag)||
            hasPathOne(matrix, i, j-1, rows, cols, str, k+1, flag)||
            hasPathOne(matrix, i, j+1, rows, cols, str, k+1, flag))
        return true;
    flag[index] = 0;
    return false;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
    int *flag = new int[rows*cols];
    for (int i = 0; i < cols*rows; i++) flag[i] = 0;
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if (hasPathOne(matrix, i , j, rows, cols, str, 0, flag)){
                delete []flag;
                flag = NULL;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    char[3][4] matrix{{a,b,c,e},{s,f,c,s},{a,d,e,e}};
    int rows = 3;
    int cols = 4;
    char str = "bcced";
    cout<<hasPath(matrix,rows,cols,&str)<<endl;;
    return 0;
}
