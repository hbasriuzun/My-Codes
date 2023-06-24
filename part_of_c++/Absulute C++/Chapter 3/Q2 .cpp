#include <iostream> 
using namespace std;

double calculate(double salary1, double salary2){
    return (salary2 - salary1) / salary1;
}

int main(int argc, char const *argv[])
{
    double salary1, salary2;
    while(true){   
        int a;
        cin >> salary1 >> salary2; 
        cout << calculate(salary1,salary2) << endl;
        cout << "Do you want to repead Y/N" << endl;
        cin >> a;
        if(a == 'Y' || a == 'y')
            continue;
        exit(1);
    }
    
    return 0;
}
