#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, f;
        cin >> n;
	    vector<int> test_case(n);
        char arr[n];
	    for(int i = 0; i < n; ++i){
	        cin >> test_case[i];
        }
	    for(int i = 0; i < n; ++i){
	        cin >> arr[i];
        }
        

        int min = 200000000;
        for (int i = 0; i < n; i++){
            if (arr[i] == '0'){
                if (min > test_case[i]){
                    min = test_case[i];}
                
            }
         }
        cout << min << endl;
            
        
	}
	
	return 0;
}
