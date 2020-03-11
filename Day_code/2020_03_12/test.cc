#include<iostream>
#include<math.h>
using namespace std;

bool isPrime(int num)
{
    if (num <= 3) {
        return num > 1;
    }
    if (num % 6 != 1 && num % 6 != 5) {
        return false;
    }
    int sq = sqrt(num);
    for (int i = 5; i <= sq; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    int n = 0;
    while(cin >> n)
    {
        int count = 0;
        int temp = n;
        for(int i = 2; i < sqrt(n)+1; ++i)
        {
                if(isPrime(temp))
                {
                    count++;
                    break;
                }
            if(0 == temp % i)
            {
                count++;
                while(0 == temp % i)
                {
                    temp /= i;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
