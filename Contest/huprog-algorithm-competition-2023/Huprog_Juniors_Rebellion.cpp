#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int xi, yi, zi;
        cin >> xi >> yi >> zi;
        
        int unbiased_group = max(xi, zi);
        int ai_group = min(xi, zi, (xi+zi+yi-unbiased_group)/2);
        int computer_group = min(xi, zi, (xi+zi+yi-unbiased_group)/2);
        int largest_group = max(ai_group, computer_group);
        
        cout << largest_group << endl;
    }
    
    return 0;
}