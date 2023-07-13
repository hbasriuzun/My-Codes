
#include <iostream>
#include <iterator>
#include <set>
#include <array>
#include <algorithm>
using namespace std;

int main(){
    std::set<int> mySet = {10, 20, 30, 40, 50};
    auto it1 = mySet.lower_bound(25);
    int index = std::distance(mySet.begin(), it1);
    cout << index << endl;
    cout << *it1 << endl << endl;

     it1 = mySet.lower_bound(30);
     index = std::distance(mySet.begin(), it1);
    cout << index << endl;

    auto it2 = mySet.upper_bound(25);
    index = std::distance(mySet.begin(), it2);
    cout << index << endl;

     it2 = mySet.upper_bound(30);
     index = std::distance(mySet.begin(), it2);
    cout << index << endl;

     it2 = mySet.lower_bound(45);
    index = std::distance(mySet.begin(), it2);
    cout << index << endl;
}