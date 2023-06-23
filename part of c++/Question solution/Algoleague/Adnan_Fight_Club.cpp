#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    map<int,bool> arr;
    ll check;
    while (n--)
    {
        cin >> check;
        if(check == 1){
            int num;
            cin >> num;
            arr[num] = true;
        }else{
            int a, b;
            cin >> a >> b;
            if(arr[a] == true && arr[a+b] == true && arr[a-b] == true){
                cout << "GG EZ" << endl;
            }else{
                cout << "GLHF" << endl;
            }
        }
    
    }
}