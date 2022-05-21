#include <iostream>
using namespace std;

int normal_fibonacci(int n){

    int result = 1, previous = 1;

    for( int i=2 ; i<=n ; i++ ){
    int tmp = result;
    result += previous;
    previous = tmp;
    }
    return result;
 }

 int recurison_fibonacci(int n){
     int a = 31;
        cout << a << endl;
     if(n==0 || n==1)
        return 1;
    return recurison_fibonacci(n-1) + recurison_fibonacci(n-2);
 }

int main(int argc, char const *argv[])
{
    int a=45;
    cout << "Normal fibonacci calculate: " <<normal_fibonacci(a)<< endl <<"Recursion fibonacci calculate: " << recurison_fibonacci(a);
    return 0;
}
