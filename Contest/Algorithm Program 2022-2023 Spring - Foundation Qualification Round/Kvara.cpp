#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<pair<int, int>> fields(n);

    for (int i = 0; i < n; i++) {
        fields[i] = make_pair(a[i], b[i]);
    }

    sort(fields.begin(), fields.end());

    int ans = 0;

    

    return 0;
}