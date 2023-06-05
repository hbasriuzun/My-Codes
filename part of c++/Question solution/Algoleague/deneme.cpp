#include <iostream>
#include <string>
using namespace std;


string countDivisibleSums(string n){
    string count=0,sum=0;
    int i = n.size() ;
    int j = n.size() ;

    for(i=1;i<=n.size();i++){
        sum.length()+=i;
        if(sum.size()%(i+1) == 0){
            count.length()++;
        }
    }
    return count;
}

int main() {
    string n,result;
    cin>>n;

    result= countDivisibleSums(n);
    cout<<result;
    return 0;
}