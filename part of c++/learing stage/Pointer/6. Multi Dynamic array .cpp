#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int d1,d2;

    cout << "Enter the row and column dimensions of the array:\n";
    cin >> d1 >> d2;

    int **m = new int*[d1];
    
    for (size_t i = 0; i < d1; i++)
        m[i] = new int[d2];
    
        cout << "Enter " << d1 << " rows of " << d2 << " integers each:\n";

    for (size_t i = 0; i < d1; i++)
    {
        for (size_t j = 0; j < d2; j++)
            cin >> m[i][j];        
    }
    
    cout << "Echoing the two-dimensional array:\n";
    for (size_t i = 0; i < d1; i++)
    {
        for (size_t j = 0; j < d2; j++)
            cout << m[i][j] << "  ";
        cout << endl;
        
    }
    
    for (size_t i = 0; i < d1; i++)
        delete [] m[i];
    
    delete[] m;
    m = nullptr;
    return 0;
}
