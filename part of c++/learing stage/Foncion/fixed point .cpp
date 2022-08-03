#include <iostream>
#include <cmath>
using namespace std;

int raund(double num);

int main(int argc, char const *argv[])
{
    double num1 = 25.5667;
    cout << raund(num1) << endl;
    


    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);

    cout << num1;

    
    return 0;
}

int raund(double num){
    return static_cast<int>(floor(num + 0.5));
}