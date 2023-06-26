//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void printle(vector<int> arr, int n){
    vector<int> arr2(n);
    if(n == 1){
        cout << arr[0] + arr[1] << endl;
        return;
    }
    for(int i = 0; i < n; i++){
        arr2[i] = arr[i] + arr[i+1];
    }
    printle(arr2, n-1);
    for(int i = 0; i < n; i++){
        cout << arr2[i] << " ";
    }
    cout << endl;
}

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    printle(arr, n-1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
	return 0;
}
