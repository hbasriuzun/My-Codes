
#include <bits/stdc++.h>

using namespace std;


int main() {
    long long a,b,temp,c;
    cin>>a;
    cin>>b;
    if(b>a){
        int i = b/(a*2);
        temp = b%a-i;
        b= temp + i;
        if(b%2 == 0){
    b = b/2;    
            b = b*3;
            cout<<b-i << " " <<b;
        }
        else if(b%2 == 1){
            b=b-i;
            b = b/2;
            b = b*3;
            cout<<b+i;
        }
    }
    else{
        if(b%2 == 0){
            b = b/2;
            b = b*3;
            cout<<b -1 << " " <<b;
        }
        else if(b%2 == 1){
            b=b-1;
            b = b/2;
            b = b*3;
            cout<<b+1;
        }
    }

    return 0;
}