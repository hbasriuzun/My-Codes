#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_map>

#define endl "\n"
const int N = 1e5+5;

using namespace std;
typedef long long ll;
typedef uint64_t ull;

unordered_map<ull,ull> divisor;

ull Calculate_positive_divisor_recursive(ull num){
    if(divisor.find(num) != divisor.end()){
        return divisor[num];
    }
    ull sum = 0,check;
    for (ull i = 1; i <= sqrt(num); ++i){
            
            if (num % i == 0){
                check = Calculate_positive_divisor_recursive(i);
                divisor[i] = check;
                sum += check;
            
            
            if(i != num/i && num/i != num && num % (num / i) == 0){
                check = Calculate_positive_divisor_recursive(num/i);
                divisor[num/i] = check;
                sum += check;
            }
            }
        
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    divisor[1] = 1;
    divisor[2] = 1;
    divisor[3] = 1;

    ull n;
    cin >> n;
    if (n == 0) {
        cout << 0;  
        return 0;
    }
    clock_t startTime = clock();
    cout << Calculate_positive_divisor_recursive(n) << endl;
    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

    return 0;
}