#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
    string s,s2;
    cin >> s;
    int divide = 0,num,check;

    
        check = s.back() - '0';
    


    if (s == "1" || s == "2")
    {
        cout << 0 << endl;
        return 0;
    }
    
    s.pop_back();
    if(check / 2 == 0 && check != 0){
        s += to_string(check - 1);
    }else
        s += to_string(check); 
        
    

    for (char ch : s) {
        int digit = ch - '0'; 

            int result = (divide * 10 + digit) / 2; 
            divide = (divide * 10 + digit) % 2; 

            s2 += to_string(result);
    }

    check = s[0] - '0';
    if( check == 1){
        auto i = s2.begin();
        i++;
        for(; i != s2.end(); i++){            cout << *i;
        }
        return 0;
    }
    cout << s2 << endl;


    return 0;
}