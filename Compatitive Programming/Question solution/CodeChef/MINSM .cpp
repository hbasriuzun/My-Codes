#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int> arr[n];
	    for(int i; i<n; ++i)
	        cin >> arr[i];

	    for(int i; i<n-1;++i){
	        gcd(arr[i],arr[i+1]);
	    }
	    
	}
	return 0;
}
