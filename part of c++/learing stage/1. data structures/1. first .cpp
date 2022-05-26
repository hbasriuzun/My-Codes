#include <iostream>
#include <new>
#include <stdlib.h>
#include <stdio.h>


    using namespace std;

int main(int argc, char const *argv[])
{
    int i;
    
    int *list = new int[2];

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    int* tmp = new int[3];
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }
    
    for ( i = 0; i < 4; i++)
    {
        tmp[i] = list[i];
    }
    
    tmp[3] = 4;

    list = tmp;

    free(list);

    for ( i = 0; i < 4; i++)
    {
        cout << list[i] << endl; 
    }
    
    free(list);
    return 0;
}
