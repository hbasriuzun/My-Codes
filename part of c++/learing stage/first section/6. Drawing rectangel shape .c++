#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
    int height, width;
    char symbol;
    cout << "Height: ";  cin >> height; 
    cout << "widht: ";  cin >> width;
    cout << "symbol: ";  cin >> symbol;

    for ( int i = 0; i < height; i++)
    {
        for (int j = 0; j < width ; j++)
        {
            cout << setw(3) << symbol;
        }
            cout << endl;
    }
    
    return 0;
}
