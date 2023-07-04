#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	for(int i; i < t; i++){
	    int n,a,b,c;
	    cin >> n >> a >> b >> c;
	    
	    if(b < n || (a+c) < n )
	        cout << "NO" << endl;
        else{
            cout << "YES" << endl;
        }	    
	}
	return 0;
}
