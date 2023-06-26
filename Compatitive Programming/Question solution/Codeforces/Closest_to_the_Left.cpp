#include <iostream>

#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin >> n >> q;
    
    int a[n];
    
    for(int& x : a){
        cin >> x;
    }
    
    while(q--){
        int x,l = -1,r = n-1,mid;
        cin >> x;

        while (l<r)
        {
            mid = (l+r+1)/2;
            if(a[mid]<=x)
                l = mid;
            else
                r = mid-1;
        }
        cout << l+1 << endl;
        


    }
    
    cout << l + 1 << endl;
    return 0;
    
}