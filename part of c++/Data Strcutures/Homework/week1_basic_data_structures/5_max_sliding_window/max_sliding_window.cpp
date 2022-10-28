#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
using std::cin;
using std::cout;
using std::vector;
using std::max;

void max_sliding_window_naive(vector<int> const & A, int w) {
    int i,max_windows=0;
    deque <int> windows;
    for ( i = 0; i < w; i++){
        windows.push_front(A[i]);
        max_windows = max(max_windows,windows.front());
    }
    cout << max_windows << " ";
    for ( i = w; i < A.size(); i++){
        if(max_windows == A[i]){
            windows.pop_back();
            max_windows=max(A[i],max_windows);
            windows.push_front(A[i]);
            cout << max_windows << " ";
            continue;
        }
        if(windows.back() == max_windows){ 
            max_windows=0;
            windows.pop_back();
            windows.push_front(A[i]);
            for (size_t j = 0; j < w; j++){
                max_windows=max(windows[j],max_windows);
            }
            cout << max_windows << " ";
            continue;
        }
        windows.pop_back();
        max_windows=max(A[i],max_windows);
        windows.push_front(A[i]);
        cout << max_windows << " ";
    }
    



    /* for (size_t i = 0; i < A.size() - w + 1; ++i) {
        int window_max = A.at(i);
        for (size_t j = i + 1; j < i + w; ++j)
            window_max = max(window_max, A.at(j));

        cout << window_max << " ";
    } */

    return;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window_naive(A, w);

    return 0;
}
