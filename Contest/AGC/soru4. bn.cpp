#include <iostream>
#include <new>
using namespace std;

int main(int argc, char const *argv[])
{
    
    int i,n;
  int * p;
  cout << "How many numbers would you like to type? ";
  cin >> i;


    int rows , cols ;
    cin >> rows >> cols;
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i)
    matrix[i] = new int[cols];




    return 0;
}
