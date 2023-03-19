#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll hazelnuts, num  = 1, num2, count = 0;
    cin >> hazelnuts;
    unordered_map <ll, ll> map;
    while(hazelnuts > num){
        map[num] = 0;
        num *= 2;
        count++;
    }
    num2 = num;
    num /= 2;
    hazelnuts -= num;

    ll bolum = (hazelnuts + num-1)/2;
    bolum -= hazelnuts;
    while (bolum != 0)
    {
        
        if(0 <= bolum - num){
            bolum -= num;
            map[num] = 1;
        }
        num /= 2;
    }
    
    cout << count << endl;
    for(int i = 1; i < num2; i *= 2){
        cout << map[i] <<  endl;}
    return 0;
}