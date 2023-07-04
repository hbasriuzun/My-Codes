#include <iostream>
#include <vector>


using namespace std;

int main() {
	
	int t;
	cin >> t;
	
	for( int i = 0; i < t; i++){
	    int n;
	    cin >> n;
	    vector <int> situation(n-1);
	    
	    int sum1 = 0,max1;
	    for (int j = 0; j < n; j++){
	        cin >> situation[j];
	        sum1 += situation[j];
	        max1 = max(max1,situation[j]);
	    }
	    sum1 += max1;
	    cout << sum1 << endl;
	   }
	
	
	return 0;
}
