#include <bits/stdc++.h>
#include <chrono>

const int N = 1e5+5;

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

class Solution {
public:
    unordered_map<ll,ll> fib_map;

    ll fib(ll n){
        fib_map[0] = 1;
        fib_map[1] = 2;
        return fib2(n);
    }
    
    ll fib2(ll n) {
        if(n < 0)
            return 0;
        else if(fib_map.find(n) != fib_map.end()){
            return fib_map[n];
        }else{
            fib_map[n] = fib2(n-1) + fib2(n-2);
            return  fib_map[n];
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    //cin.tie(NULL);
    unsigned long long sum = 0;
    Solution s;

    // for(ll i = 1; i< 32;i++){
    //     if(s.fib(i) % 2 == 0)
    //         sum += s.fib(i);
    //     cout << "" << s.fib(i) << endl;
    // }
    //while(1){
        ll n;
        cin >> n;
    auto start = std::chrono::high_resolution_clock::now(); 
        
        ll result = s.fib(n);

    auto end = std::chrono::high_resolution_clock::now();    // Bitiş zamanını kaydet
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);  // Süreyi hesapla

    std::cout << "F(" << n << ") = " << result << std::endl;
    std::cout << "Program " << duration.count() << " mikrosaniye sürdü." << std::endl;

    //}
    //cout << sum << endl;    

    return 0;
}