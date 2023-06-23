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
    vector<vector<ll>> v;
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
            v[a].push_back(b);
            v[b].push_back(a);
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


        while(cities.size() != nodes_number){
            if(cities.size() != nodes_number){
                for(ll i = 1; i <= nodes_number; i++){
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

                for(auto neighbor : v[curr]){
                    if(exploerer[neighbor])
                        continue;
                    pq.push(neighbor);
                    exploerer[neighbor] = true;
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
