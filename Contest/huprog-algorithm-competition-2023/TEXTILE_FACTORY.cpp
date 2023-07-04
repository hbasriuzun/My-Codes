#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
    unsigned long long int n;
    cin >> n;
    if(n == 1){
        cout << 1 ;
        return 0;
    }if(n == 2){
        cout << 2 ;
        return 0;
    }if(n == 3){
        cout << 2 ;
        return 0;
    }if(n == 4){
        cout << 4 ;
        return 0;
    }
    
    n = n - 4;
    n = n / 4;
    if (n = 1)
    {
        cout << 2 << endl;
    }else if (n = 2)
    {
        cout << 4 << endl;
    }else if (n = 3)
    {
        cout << 6 << endl;
    }else if (n = 4){
        cout << 8 << endl;
    }
    return 0;
}