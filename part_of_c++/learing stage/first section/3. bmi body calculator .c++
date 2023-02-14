#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float height, weight;
    cout << "Please enter height(m) and weight(kg) ";
    cin >> height >> weight;
    cout << weight / (height * height);
    if (weight / (height * height) < 18.5)
    {
        cout << "underweight" << endl;
    }
    else if (weight / (height * height)> 25)
    {
        cout << "Overweight" << endl;
    }
    else if (weight / (height * height)< 25)
    {
        cout << "Normal" << endl;
    }
    



    return 0;
}
