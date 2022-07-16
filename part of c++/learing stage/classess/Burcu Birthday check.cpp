#include <iostream>
#include <cstdlib>
using namespace std;

class DayOfYear{
    public:
        void input();
        void output();
        void set(int newMonth, int newDay);
        void set(int newMonth);
        int getMonthNumber();
        int getDay();
    private:
        int month;
        int day;
};

int main(int argc, char const *argv[])
{
    DayOfYear today, backBirhtday;
    cout << "Enter today's date: \n";
    today.input();
    cout << "Today's date is: ";
    today.output();

    backBirhtday.set(4,12);
    cout << "Burcumun dogum gunu: ";
    backBirhtday.output();

    if ((today.getMonthNumber() == backBirhtday.getMonthNumber()) && (today.getDay() == backBirhtday.getDay())){
        cout << "Happy Birhday Burcuuu I love you! \n";
    }else{
        cout << "Burcu bro sorry but today is not your birthday!\n ";
    }
    
    return 0;
}


void DayOfYear::set(int newMonth, int newDay){
    if ((newMonth >= 1) && (newMonth <= 12)) {
        month = newMonth;
    }else{
        cout << "Illegal month value ! Program aborted, \n";
        exit(1);
    }
    if ((newDay >= 1) && (newDay <= 31)){
        day = newDay;
    }else{
        cout << "Illegal day value! Program aborted. \n";
        exit(1);
    }
    
}

void DayOfYear::set(int newMonth){
    if ((newMonth >= 1) && (newMonth <= 12)) {
        month = newMonth;
    }else{
        cout << "Illegal month value ! Program aborted, \n";
        exit(1);
    }
    day = 1;
}

int DayOfYear::getMonthNumber(){
    return month;
}

int DayOfYear::getDay(){
    return day;
}

void DayOfYear::input(){
    cout << "Enter the month as a number: ";
    cin >> month;
    cout << "Enter the day of the month: ";
    cin >> day;
    if ((month < 1) || (month > 12) || (day < 1) || (day > 31)){
        cout << "Illegal date! Program aborted. \n";
        exit(1);
    }
}

void DayOfYear::output(){
    switch (month)
    {
    case 1:
        cout << "January "; break;
    case 2:
        cout << "February"; break;
    case 3:
        cout << "March"; break;
    case 4:
        cout << "April "; break;
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
    cout << day << endl;
}