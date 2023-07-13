#include <bits/stdc++.h>

#define endl "\n"
const int N = 1e5+5;

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

bool search(vector<int> &a, int target){
    int n = a.size();
    int l = 0, r = n-1;
    while(l <= r){
        int mid = (l+r)/2;
        if(a[mid] == target) return true;
        if(a[mid] > target) r = mid-1;
        else l = mid+1;
    }
    return false;
}

int bineary_search_index(vector<int> &a, int target){
    int n = a.size();
    int l = 0, r = n-1;
    while(l <= r){
        int mid = (l+r)/2;
        if(a[mid] == target) return mid;
        if(a[mid] > target) r = mid-1;
        else l = mid+1;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
    sort(a.begin(), a.end());
    int target = 5;

    a.



    return 0;
}