#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int number, reversednumber;

    cin >> number;
    while (number>0)
    {
        reversednumber *= 10;
        int lastdigid = number % 10;
        reversednumber += lastdigid;
        number /= 10;
    }
        std::cout << reversednumber;

    return 0;
}
