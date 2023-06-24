#include <iostream>

using namespace std;

class DayOfYear
{
    public:
        void output();
        void input();
        int month;
        int day;
};

int main(int argc, char const *argv[])
{
    DayOfYear today, birthday;

    cout << "Enter today's date:\n";
    today.input();
    cout << "Enter your birthday:\n";
    birthday.input();
    cout << "Today's date is ";
    today.output( );
    cout << endl;
    cout << "Your birthday is ";
    birthday.output( );
    cout << endl;

    if (today.month == birthday.month && today.day == birthday.day ){
        cout << "Happy Birhtday!\n";
    }else{
        cout << "Happy Unbirthday!\n";
    }
    

    return 0;
}

void DayOfYear::output()
{

    switch (month)
    {
    case 1:
        cout << "January"; break;
    case 2:
        cout << "February"; break;
    case 3:
        cout << "March"; break;
    case 4:
        cout << "April"; break;
    case 5:
        cout << "May"; break;
    case 6:
        cout << "June"; break;
    case 7:
        cout << "July"; break;
    case 8:
        cout << "August"; break;
    case 9:
        cout << "Semptenber"; break;
    case 10:
        cout << "October"; break;
    case 11:
        cout << "Novamber"; break;
    case 12:
        cout << "December"; break;
    
    default:
        cout << "Error in DayOfYear::output."; break;
    }
    cout << day;
}

void DayOfYear::input()
{
    cout << "Enter the day of the month: ";
    cin >> day;

    cout << "Enter month as a number: ";
    cin >> month;
    
}



