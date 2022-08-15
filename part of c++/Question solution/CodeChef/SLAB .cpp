#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        int num, sum1 = 0, sum2 = 0;
        cin >> num;

        
        if  ( num > 250000){
            sum1 += num / 20 ; 
            if (sum1 > 250000 / 20)
                sum1 = 250000 / 20;
                sum2 += sum1;
            }
        if  ( num > 500000){
            sum1 = 0;
            sum1 += (num - 500000) / 10; 
            if (sum1 > 500000 / 10)
                sum1 = 500000 / 10;
                sum2 += sum1;
            }
        if  ( num > 750000){
            sum1 = 0;
            sum1 += (num - 750000) * 85 / 100; 
            if (sum1 > 750000 * 85 / 100)
                sum1 = 750000 * 85 / 100;
                sum2 += sum1;
            }
        if  ( num > 1250000){
            sum1 = 0;
            sum1 += (num - 1250000) * 80 / 100; 
            if (sum1 > 1250000 * 80 / 100)
                sum1 = 1250000 * 80 / 100;
                sum2 += sum1;
            }
        if  ( num > 1500000){
            sum1 = 0;
            sum1 += (num - 1500000) * 75 / 100;
            if (sum1 > 1500000 * 75 / 100)
                sum1 = 1500000 * 75 / 100;
                sum2 += sum1;
            }
        cout << num - sum2 << endl;
    
    }
    
    return 0;
}
