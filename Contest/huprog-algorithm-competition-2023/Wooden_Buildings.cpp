#include <iostream> 
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int A, B, C;
    unsigned long long int sum = 0;
    cin >> A >> B >> C;

    vector<int> ai, bi, ci;

    for (int i = 0; i < A; i++)
    {
        int a;
        cin >> a;
        ai.push_back(a);
    }
    for (int i = 0; i < B; i++)
    {
        int b;
        cin >> b;
        bi.push_back(b);
    }
    for (int i = 0; i < C; i++)
    {
        int c;
        cin >> c;
        ci.push_back(c);
    }

    sort(ai.begin(), ai.end(),[](int &e1, int &e2){ return e1>e2; });
    sort(bi.begin(), bi.end(),[](int &e1, int &e2){ return e1>e2; });
    sort(ci.begin(), ci.end(),[](int &e1, int &e2){ return e1>e2; });

    cout << bi.front() << endl;
    while((!bi.empty() && !ai.empty()) || (!bi.empty() && !ci.empty()) || (!ai.empty() && !ci.empty())){
        
        
    }
}