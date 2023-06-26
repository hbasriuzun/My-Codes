#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n,i,k,a;
    cin >> n >> k;
    
    a = n * (3/2);
    int arr[a];
    arr[0] = 0;
    for ( i = 1; i < a; i++)
    {
        arr[i] = arr[i -1] + 1;
    }
    
    for ( i = 0; i < k; i++)
    {
        
    }
    

    return 0;
}
