#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    
    int M,N,A,i;
    cin >> M >> N;
    cin >> A;
    

    int** B = new int*[M];
    int** K = new int*[M];
    int** L = new int*[M];
 
    


    for ( i = 0; i < M; i++)
    {
        B[i] = new int[N];
        for (int j = 0; j < N; j++) {
            B[i][j] = rand() % 100;
            std::cout << B[i][j] << " ";
        }
        std::cout << std::endl;
    }
 
    for ( i = 0; i < A; i++)
    {
        
    }
    
    

    return 0;
}
