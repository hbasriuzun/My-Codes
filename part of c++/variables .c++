#include <iostream>
using namespace std;

int main()
{
    float annualsalary = 12000;
    cout <<"Enterde Salary: ";// cin >> annualsalary;
    float monthlysalary = annualsalary/12;
    cout <<"your monthly salary is: "<< monthlysalary << endl;
    cout <<"your salary is: " << annualsalary << endl;  
    
    cout << "size of int: " << sizeof(int) << "bytes"  << endl;
    cout << "size of double: " << sizeof(double) << "bytes" << endl;
    cout << "int max value: " << double << "bytes" << endl;
    cout << "int max value: " << INT_MIN << endl;   


    cout << "size of unsignet int: " << sizeof(unsigned int) << "bytes" << endl;
    cout << "int max value: " << UINT_MAX << endl;

    system("pause>0");
}