#include <iostream>

using namespace std;

int main() {
     int n,q;
     cin >> n >> q;
    // int **nums = new int*;
    // for (int i = 0; i < n; i++) {
    //     *(nums + i) = new int;
    //     int length;
    //     cin >> length;
    //     for (int j = 0; j < length; j++) {
    //         cin >> *(*(nums + i)+j); 
    //     }
    // }
    // int i,j;
    // for(int k = 0;k < q; k++){
    //     cin >> i >> j;
    //     cout << *(*(nums + i)+j) << endl;
    // }
        int **arr = new int*[n];
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            arr[i] = new int(k);
            for (int j = 0; j < k; j++) {
                cin >> arr[i][j];
            }
        }
        
        for (int k = 0; k < q; k++) {
            int i,j;
            cin >> i >> j;
            cout << arr[i][j] << endl;
        }
    return 0;
}

