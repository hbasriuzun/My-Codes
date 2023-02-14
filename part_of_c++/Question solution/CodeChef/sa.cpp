#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	  while(t--){
	    int days, days_grams_protein, total_grams_protein = 0,i;
	    cin >> days >> days_grams_protein;
	    vector <int> grams(days);
	      for(int j; j < days; j++ )
	          cin >> grams[days];
	    for(i = 0; i < days; ++i){
	      
	      total_grams_protein += grams[i];
	      if(days_grams_protein > total_grams_protein){
	          cout << "NO " << days_grams_protein - total_grams_protein << endl;
	          break;
	      }else{
	          total_grams_protein - days_grams_protein;
	      }
	      
	    }
	    if(i == days){
	    cout << "YES" << endl;}
	}
	return 0;
}
