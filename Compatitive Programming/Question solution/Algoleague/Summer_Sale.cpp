#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main(){
    ll games_size, money, number_of_queries;
    cin >> games_size >> money;

    vector<ll> games_price(games_size);

    for(ll i = 0; i < games_size; i++){
        cin >> games_price[i];
    }

    cin >> number_of_queries;
    ll query;
    int count  = 0;
    while(number_of_queries--){
        cin >> query;
        for(auto &num: games_price)
            count += money + query >= num && query - money <= num;
        cout << count;
    }
    
        

}//end

    

