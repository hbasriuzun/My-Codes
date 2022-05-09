#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n,count=0,num,num2=0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num > num2)
        {
            num2 = num;
            count++;
        }
        
    }
    count--;
    cout << count;
    return 0;
}
