#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,count=0;
    cin >> n;
    vector <int> arr(n,0);
    vector <int> arr2(n,0);
    vector <int> arr_num(10000,0);
    vector <int> arr_num2(10000,0);

    for (size_t i = 0; i < n; i++)
        cin >> arr[i];
    
    for (size_t i = 0; i < n; i++)
        cin >> arr2[i];
    
    for (size_t i = 0; i < n; i++)
    {
        if(arr[i]!=arr2[i]){
            arr[arr[i]]++;
            arr[arr2[i]]++;
            count++;
        
    }
    }
    

  /*  for (size_t i = 0; i < n; i++)
    {
        if(arr[i]!=arr2[i]){
            arr[arr[i]]++;
            arr[arr2[i]]++;
            count++;
        }
    }
    


    for (size_t i = 0; i < n; i++)
    {

        if(arr[i] != arr2[i]){
            count++;
            arr[arr[i]]++;
            arr[arr2[i]]++;
            continue;
        }else if(arr[i]!=i){
            count++;
            arr[arr[i]]++;
            arr[arr2[i]]++;
            continue;
        }else if(arr2[i] != i && ){
            count++;
            arr[arr[i]]++;
            arr[arr2[i]]++;
            continue;
        }
    }*/
    
    cout << n-count;
	return 0;
}