#include <bits/stdc++.h>

using namespace std;

int main(){
    
    array<int,9> a = {0,5,2,7,9,3,4,9,10};

    sort(a.begin(),a.end());  

    for(auto b : a)                             
        cout << b << endl;                      
    

    int target = 10;
    int left = 0,right = a.size(), mid ;
    while(left < right){
        mid = (left + right + 1) / 2;
        if(a[mid] == target)
            break;

        if(target > a[mid]){
            left = mid  - 1;
            continue;
        }else{
            right = mid -1;
        }

    }


}