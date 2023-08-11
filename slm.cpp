#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    array <int,1024> s;
    int n;
    cin>>n;
    
    for(int i=0;i<1024;i++){
        cin>>s[i];
    }
 // I want to find number that not in array s with binary search
    int l=0,r=1023;
    while(l<=r){
        int mid=(l+r)/2;
        if(s[mid]==n){
            cout<<mid<<" "<<s[mid];
            break;
        }
        else if(s[mid]>n){
            r=mid-1;
            cout << 
        }
        else{
            l=mid+1;
        }
    }
    



    return 0;
}

