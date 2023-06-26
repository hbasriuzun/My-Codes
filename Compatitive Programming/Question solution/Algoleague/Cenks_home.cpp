#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,c,cnt = 1;
    cin >> n >> c;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    
    for(int i = 0; i < n; i++){
        c -= arr[i];
        if(c >= 0)
            cnt++;
        else{
            cout << cnt << endl;
            return 0;
        }
    }
    cout << "EV" << endl;
    return 0;
}