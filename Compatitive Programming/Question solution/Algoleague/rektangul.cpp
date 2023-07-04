#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>


using namespace std;
typedef long long ll;

int main(){
    int n,num = 1,sum = 0;
    cin >> n;

    while((n / num) - (num - 1) > 0){
        sum += (n / num) - (num - 1);
        num++;
    }
    cout << sum << endl;
}