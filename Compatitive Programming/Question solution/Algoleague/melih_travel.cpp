#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>


using namespace std;
typedef unsigned long long ull;
typedef long long ll;

class DFS {
public:
    vector<set<ll>> v;
    map<ll, bool> exploerer;
    ll nodes_number;

    void get_graph() {
        ll edges_number;
        cin >> nodes_number;
        if(nodes_number == 1){
            return;
        }
        cin >> edges_number;
        v.resize(nodes_number + 1);
        for(ll i = 0; i < edges_number; i++){
            ll a, b;
            cin >> a >> b;
            v[a].insert(b);
            v[b].insert(a);
        }
    }


    vector<ll> visit_cities(){
        get_graph();
        if(nodes_number == 1){
            vector<ll> cities;
            cities.push_back(1);
            return cities;
        }
        stack<ll> pq;
        vector<ll> cities;


            ll i = 1;
        while(cities.size() != nodes_number){
            if(cities.size() != nodes_number){
                for(; i <= nodes_number; i++){
                    if(!exploerer[i]){
                        pq.push(i);
                        exploerer[i] = true;
                        break;
                    }
                }
            }

            while(!pq.empty()){
                ll curr = pq.top();
                pq.pop();
                cities.push_back(curr);

                    if(v[curr].empty())
                        continue;
                    for(auto it=v[curr].rbegin(); it != v[curr].rend(); it++){
                        if(exploerer[*it])
                            continue;
                        pq.push(*it);
                        exploerer[*it] = true;
                        break;
                    }

                
            }
                
        }
        return cities;
    }
};

int main() {
    DFS dfs;

    for(auto i : dfs.visit_cities())
        cout << i << " ";
    



    return 0;
}
