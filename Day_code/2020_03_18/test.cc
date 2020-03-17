#include<iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{

    int n, num = 0, ans = 0;
    cin >> n;
    char *str;
    str = (char*)malloc(n * sizeof(char) + 1);
    /*sizeof(char)就是一个char类型占用的空间大��strlen(str)为字符串str的长度，因为字符串最后还有个'\0'表示字符串结尾，所以这一块就表示str字符串占用的内存空间的总大小。*/
    cin >> str;
    int j = n - 1;
    int p = 0;
    for(int i = 0; i < j; i++)
    {//从左边起依次扫描，每记录一个字母，就寻找从右边起最近的与它相同的字母
        for(int k = j; k >= i; k--)
        {
            if(k == i)//在字串里单独存在
            {
                num++;
                if(n % 2 == 0 || num > 1)
                {
                    cout << "Impossible" << endl;
                    return 0;

                }
                p = n / 2 - i;//它到字串中间的步数,但是不需要移动
                cout << "i = " << i << endl;
                break;

            }
            else if(str[k] == str[i])
            {
                ans += j - k;
                cout << " ans += j - k;  ans = " << ans << endl;
                for(int m = k; m < j; m++)
                {
                    str[m] = str[m + 1];//移动
                }
                str[j] = str[i];
                j--;
                break;
            }

        }
    }
    cout << ans + p << endl;
    return 0;
}
