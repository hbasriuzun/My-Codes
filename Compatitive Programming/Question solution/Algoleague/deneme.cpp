#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main() {
    set <int> s;

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.erase(*s.end()); 
    cout << *s.end();
    cout << *s.rend();
    cout << *s.end();
    return 0;
}