#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float num1 , num2;
    char operation;
    cout << "Please enter the number and operation :" << endl;
    cin  >> num1 >> operation >> num2;

    switch (operation)
    {
    case '+' : cout << num1 << operation << num2 << "=" << num1 + num2 << endl; break;
    case '-' : cout << num1 << operation << num2 << "=" << num1 - num2 << endl; break;
    case '/' : cout << num1 << operation << num2 << "=" << num1 / num2 << endl; break;
    case '*' : cout << num1 << operation << num2 << "=" << num1 * num2 << endl; break;
    case '%' :
        bool isnum1int, isnum2int;
        isnum1int = ((int)num1 == num1);
        isnum2int = ((int)num2 == num2);
        
        if (isnum1int && isnum2int)
            {
                cout << num1 << operation << num2 << "=" << (int)num1 % (int)num2 << endl; break;
            }
        else 
            {cout << "not valid";}
        
    
    
    default:
        break;
    }

    return 0;
}
