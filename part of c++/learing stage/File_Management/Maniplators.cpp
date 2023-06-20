#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    double n = 41.2131231;
    cout << "n: " << setprecision(5) << n << endl;
    cout << "n: " << setprecision(4) << n << endl;
    cout << "n: " << setprecision(3) << n << endl;
    cout << "n: " << setprecision(2) << n << endl;
    cout << "n: " << setprecision(1) << n << endl;

    cout << endl;

    cout << "n: " << fixed << setprecision(7) << n << endl;
    cout << "n: " << fixed << setprecision(4) << n << endl;
    cout << "n: " << fixed << setprecision(3) << n << endl;
    cout << "n: " << fixed << setprecision(2) << n << endl;
    cout << "n: " << fixed << setprecision(1) << n << endl;

    cout << left <<  setw(10) << fixed << setprecision(5) << n ;
    cout << setw(11) << fixed << setprecision(5) << n << endl;
    
    return 0;
}