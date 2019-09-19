#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
int main()
{
    double x1,y1,x2,y2,x3,y3,x4,y4;
    scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
    scanf("%lf%lf%lf%lf",&x3,&y3,&x4,&y4);
    double ax,ay,bx,by;
    ax=max(min(x1,x2),min(x3,x4));
    ay=max(min(y1,y2),min(y3,y4));
    bx=min(max(x1,x2),max(x3,x4));
    by=min(max(y1,y2),max(y3,y4));
    if(ax<bx&&ay<by)
    {
        printf("%.2lf",(ax-bx)*(ay-by));

    }
    else
    {
        printf("0.00");

    }
    return 0;

}


