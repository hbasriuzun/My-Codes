#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    //User enter integer numbers.
    //Program write out if that number is even or odd 
    //Diagram is https://ibb.co/XCmYMqC

    int number1;

    cout << "Please enter the number." << endl;
    cin >> number1;

    if (number1 % 2 == 0)
    {
        cout << "your number is even" << endl;
    }
    else if (number1 % 2 == 1)
    {
        cout << "your number is add" << endl;
    }
    
    system("cls");

    int a=31 ,b=31;
    cout << (a != b) << endl;

    system ("pause<0");
    return 0;
}
