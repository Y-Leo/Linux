#include <iostream>
using namespace std;
 
void QuickSort(int* arr,int left, int right)
{
        if (left > right)
        {
                    return;
                        
        }
            int i = left;
                int j = right;
                //最左边的为准基数
                    int flag = arr[left];
                while (i != j)
                {
                    //从右侧找到一个比标记小的值
                    while (arr[j] > flag && i < j)
                    {
                        j--;
                    }
                    //从左侧找到一个比标记大的值
                    while (arr[i] <= flag && i < j)
                    {
                        i++;
                    }
                    //交换找到的值,使左边小,右边大
                    int temp = 0;
                    if (i<j)
                    {
                        temp = arr[j];
                        arr[j] = arr[i];
                        arr[i] = temp;
                    }
                }//完成while循环,此时i=j

                //交换准基数和相遇值,即将中值归位
                arr[left] = arr[i];
                arr[i] = flag;

                //将中值左,右侧的数据分别进行排序(递归)
                QuickSort(arr, left, i - 1);
                QuickSort(arr, i + 1, right);

}

int main()
{
    int array[10] = { 879, 1, 34, 45, -123, 34, 5, 0, 45, 1  };
    QuickSort(array,0,9);

    //范围for循环打印数组
    for (auto e:array)
    {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}


