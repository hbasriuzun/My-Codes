#include <iostream>
using namespace std;
bool isprimenumber(int number)
{
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 100000; i++)
    {
        if (isprimenumber(i))
        {
            cout << i << "is prime number" << endl;
        }
        
    }
    
    return 0;
}
