#include <iostream>
using namespace std;

int main()
{
    for(int i = 1000; i < 10000; ++i)
    {
        
        if(((i%10)*10+(i%100-i%10)/10) == (i/100))
            cout << i <<" ";
    }
    cout << endl;
    return 0;

}



