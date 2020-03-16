#include<iostream>
#include <math.h>
using namespace std;
int N;//棋盘大小
int nn[8][8];//棋盘
int black[8];//黑皇后放置的位置
int white[8];//白--
int ans=0;//个数

bool panduan(int n,int wb[])
{
    for(int i=0;i<n;i++)//放置行与之前已经所有行进行比较
    {
        if((wb[i]==wb[n])||(abs(n-i)==abs(wb[n]-wb[i])))//因为是逐行放置，所以只用判断列和对角线
            return false;
    }
    return true;
}

void startwhite(int n)
{
    if(n==N)
        ans++;
    else
    {
        for(int i=0;i<N;i++)
            if(black[n]!=i && nn[n][i]!=0)//加一层判断，是否该位上有黑皇后
            {
                white[n] = i;
                if( panduan(n,white)  )
                {
                    startwhite(n+1);
                }
            }
    }
}

void startblack(int n)
{
    if(n==N)
        startwhite(0);
    else
        for(int i=0;i<N;i++)//循��列数
            if(nn[n][i]!=0)//该位上0/1
            {
                black[n] = i;//记录这一行的皇后放置的列数
                if( panduan(n,black)  )
                    startblack(n+1);//放置下一个，否则准备回溯
            }
}

int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>nn[i][j];
    startblack(0);//从0行开始
    cout<<ans;//全局变量
    return 0;
}



