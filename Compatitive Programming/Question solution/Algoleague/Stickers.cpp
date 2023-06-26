#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef unsigned long long ull;

int main(){
    ull number, times = 1;
    cin >> number;

    while(true){
        while (number != 0)
        {
            if(number % 10 == 0){
                number /= 10;
                continue;
            }
            times *= number % 10;
            number /= 10;
        }
        number = 1;
        if(times < 10){
            cout << times << endl;
            return 0;
        }
        while (times != 0)
        {
            if(times % 10 == 0){
                times /= 10;
                continue;
            }
            number *= times % 10;
            times /= 10;
        }
        times = 1;
        if(number < 10){
            cout << number << endl;
            return 0;
        }
    }
}