#include <iostream>

float func(float a,int b)
{
    float m = 1, n = 1;
    int i;
    for(i = 1; i < b; ++i)
    {
        m *= a/i;
        n+=m;
    }
    return n;
}

int main()
{
    float a = 2.0;
    int b = 2;
    float n = func(a,b);
    std::cout<<n<<std::endl;
    return 0;
}
