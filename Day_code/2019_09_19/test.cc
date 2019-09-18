#include <iostream>
using namespace std;

int main()
{
    int h=1,m=0;
    cin>>h>>m;
    if(m==0)
    {switch(h)
        {
            case 0:cout<<"zero o'clock";break;
            case 1:cout<<"one o'clock";break;
            case 2:cout<<"two o'clock";break;
            case 3:cout<<"three o'clock";break;
            case 4:cout<<"four o'clock";break;
            case 5:cout<<"five o'clock";break;
            case 6:cout<<"six o'clock";break;
            case 7:cout<<"seven o'clock";break;
            case 8:cout<<"eight o'clock";break;
            case 9:cout<<"nine o'clock";break;
            case 10:cout<<"ten o'clock";break;
            case 11:cout<<"eleven o'clock";break;
            case 12:cout<<"twelve o'clock";break;
            case 13:cout<<"thirteen o'clock";break;
            case 14:cout<<"fourteen o'clock";break;
            case 15:cout<<"fifteen o'clock";break;
            case 16:cout<<"sixteen o'clock";break;
            case 17:cout<<"seventeen o'clock";break;
            case 18:cout<<"eighteen o'clock";break;
            case 19:cout<<"nineteen o'clock";break;
            case 20:cout<<"twenty o'clock";break;
            case 21:cout<<"twenty one o'clock";break;
            case 22:cout<<"twenty two o'clock";break;
            case 23:cout<<"twenty three o'clock";break;
            case 24:cout<<"twenty four o'clock";break;

        }
    }
    else
    {
        switch(h)
        {
            case 0:cout<<"zero ";break;
            case 1:cout<<"one ";break;
            case 2:cout<<"two ";break;
            case 3:cout<<"three ";break;
            case 4:cout<<"four ";break;
            case 5:cout<<"five ";break;
            case 6:cout<<"six ";break;
            case 7:cout<<"seven ";break;
            case 8:cout<<"eight ";break;
            case 9:cout<<"nine ";break;
            case 10:cout<<"ten ";break;
            case 11:cout<<"eleven ";break;
            case 12:cout<<"twelve ";break;
            case 13:cout<<"thirteen ";break;
            case 14:cout<<"fourteen ";break;
            case 15:cout<<"fifteen ";break;
            case 16:cout<<"sixteen ";break;
            case 17:cout<<"seventeen ";break;
            case 18:cout<<"eighteen ";break;
            case 19:cout<<"nineteen ";break;
            case 20:cout<<"twenty ";break;
            case 21:cout<<"twenty one ";break;
            case 22:cout<<"twenty two ";break;
            case 23:cout<<"twenty three ";break;
            case 24:cout<<"twenty four ";break;

        }

        if(m<=20)
            switch(m)
            {
                case 0:cout<<"zero";break;
                case 1:cout<<"one";break;
                case 2:cout<<"two";break;
                case 3:cout<<"three";break;
                case 4:cout<<"four";break;
                case 5:cout<<"five";break;
                case 6:cout<<"six";break;
                case 7:cout<<"seven";break;
                case 8:cout<<"eight";break;
                case 9:cout<<"nine";break;
                case 10:cout<<"ten";break;
                case 11:cout<<"eleven";break;
                case 12:cout<<"twelve";break;
                case 13:cout<<"thirteen";break;
                case 14:cout<<"fourteen";break;
                case 15:cout<<"fifteen";break;
                case 16:cout<<"sixteen";break;
                case 17:cout<<"seventeen";break;
                case 18:cout<<"eighteen";break;
                case 19:cout<<"nineteen";break;
                case 20:cout<<"twenty";break;

            }
        else
        {
            switch(m/10)
            {
                case 2:cout<<"twenty ";break;
                case 3:cout<<"thirty ";break;
                case 4:cout<<"forty ";break;
                case 5:cout<<"fifty ";break;

            }
            switch(m%10)
            {
                case 1:cout<<"one";break;
                case 2:cout<<"two";break;
                case 3:cout<<"three";break;
                case 4:cout<<"four";break;
                case 5:cout<<"five";break;
                case 6:cout<<"six";break;
                case 7:cout<<"seven";break;
                case 8:cout<<"eight";break;
                case 9:cout<<"nine";break;  

            }

        }

    }
    return 0;

}


