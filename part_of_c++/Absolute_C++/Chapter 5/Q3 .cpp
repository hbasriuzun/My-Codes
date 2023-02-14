#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int c;
    cin >> c;
    double* b{new double(c)};
    double  sum=0,sum2=0,S;

    for (size_t i = 0; i < c; i++)
    {

        cin >> b[i];
        sum += b[i];
    }

    for (size_t i = 0; i < c; i++)
    {
       sum2 += pow(b[i]-(sum / c),2);
    }
    
    S = sqrt(sum2 / c);

    cout << S;

    return 0;
}
