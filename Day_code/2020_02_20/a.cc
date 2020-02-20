#include <iostream>

int main()
{
    int n = 2;
    n += n -= n * n;
    std::cout<<n<<std::endl;
    return 0;
}
