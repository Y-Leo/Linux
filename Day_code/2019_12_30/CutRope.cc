#include <iostream>
#include<algorithm>

int cutRope(int number) {
    if (number <= 1)
        return 0;
    if (number == 2)
        return 1;
    if (number == 3)
        return 2;
    int timesOf3 = number / 3;
    /*  当最后绳子长度为 4 时，这时候分割成 2，2 而不是 3，1 
     *          因为2*2=4 > 3=3*1  */
    if (number - timesOf3 * 3 == 1)
        timesOf3--;
    int timesOf2 = (number - timesOf3 * 3) / 2;
    return (int)(pow(3, timesOf3))*(int)(pow(2, timesOf2));

}
int main()
{
    std::cout<<cutRope(8)<<std::endl;
    return 0;
}

