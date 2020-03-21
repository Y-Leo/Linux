#include <iostream>
#include <vector>
using namespace std;

int main(){
    int year1, month1, day1, year2, month2, day2;
    vector<int> dayofmonth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31  };
    while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
    {
        int sum = 0;
        for (int i = year1; i <= year2 - 1; ++i)
        {
            if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) 
                sum+=580;
            else
                sum += 579;

        }
        for (int i = 0; i <= month1 - 1; ++i)
        {
            int temp = 0;
            if (i == month1 - 1) 
                temp = day1 - 1;
            else 
                temp = dayofmonth[i];
            if (i != 1 && i != 2 && i != 4 && i != 6 && i != 10)
                sum -= temp * 2; 
            else 
                sum -= temp;

        }
        for (int i = 0; i <= month2 - 1; ++i)
        {
            int temp = 0;
            if (i == month2 - 1) 
                temp = day2;
            else 
                temp = dayofmonth[i];
            if (i != 1 && i != 2 && i != 4 && i != 6 && i != 10)
                sum += temp * 2; 
            else 
                sum += temp;

        }
        cout << sum << endl;

    }
    return 0;

}


