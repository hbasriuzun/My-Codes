#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	for(int i = 0; i < t; i++){
	    int n,a;
	    cin >> n >> a;
	    
	    int minus = n - a;
	    
	    if(minus > a){
	        cout << a << endl;;
	    }else if(a > minus ){
	        cout << minus << endl;;
	    }else{
	        cout << minus << endl;
	    }
	    
	}
	return 0;
}
