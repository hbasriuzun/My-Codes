#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a,b,c,d;
	
	int* num = new int[n];
	
	for(int i ; i < n; ++i ){
	    cin >> a >> b >> c >> d ;
	    int sum1,sum2;
	    sum1 = a - c;
	    sum2 = b - d;
	    
	    if(sum1 < sum2){
	        cout << "First" << endl;}
	    else if(sum2 < sum1){
	        cout << "Second" << endl;}
	    else{
	        cout << "Any" << endl;}
	        
	}
	return 0;
}
