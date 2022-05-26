#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    const int nRows = 20;
    const int nCols = 10;
    int (*name)[nCols] = new int[nRows][nCols];
    std::memset(name, 0, sizeof(int) * nRows * nCols); 
    name[0][0] = 1; 
    name[nRows-1][nCols-1] = 1; 

    int* tmp = new int[3];
    if (tmp == NULL)
    {
        free(tmp);
        return 1;
    }


    cout << name[0][0] << endl;
    delete[] name;




    return 0;
}
