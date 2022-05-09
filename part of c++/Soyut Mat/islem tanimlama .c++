#include <iostream>
using namespace std;

int sokrates(int a,int b)
{
    int sum;
    sum = (a*4) + (b*5);
    return sum;
}
int main()
{
    int a,b,i; 
    for ( i = 0; i < 200; i++)
    {
        cin >> a;
        cin >> b;
        cout << sokrates(a,b) << endl;
    }xxxxxx
    



}