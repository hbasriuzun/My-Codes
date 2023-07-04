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
        cin >> nodes_number >> edges_number;
        v.resize(nodes_number + 1);
        for(ll i = 0; i < edges_number; i++){
            ll a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
    }

    bool bfs_has_path(ll src, ll des) {
        if (src == des)
            return true;

        if (exploerer[src])
            return false;

        exploerer[src] = true;

        for (auto neighbor : v[src]) {
            if (bfs_has_path(neighbor, des))
                return true;
        }
        return false;
    }


    ll connected_components() {
        for(ll i = 1; i <= nodes_number; i++){
            exploerer[i] = false;
        }
        ll count = 0;
        for (ll i = 1; i <= nodes_number; i++) {
            if (!exploerer[i]) {
                count++;
                save_nodes_iterative(i);
            }
        }
        return count;
    }

    void save_nodes_iterative(ll src) {
        stack<ll> s;
        s.push(src);
        exploerer[src] = true;

        while (!s.empty()) {
            ll cur = s.top();
            s.pop();

            for (auto neighbor : v[cur]) {
                if (!exploerer[neighbor]) {
                    s.push(neighbor);
                    exploerer[neighbor] = true;
                }
            }
        }
    }

    ll largest_component() {
        for(ll i = 1; i <= nodes_number; i++){
            exploerer[i] = false;
        }
        ll max_size = 0;
        for (ll i = 1; i <= nodes_number; i++) {
            if (!exploerer[i]) {
                ll size = return_component_size(i);
                max_size = max(max_size, size);
            }
        }
        return max_size;
    }

    ll return_component_size(ll src) {
        if (exploerer[src])
            return 0;
        ll size = 1;
        exploerer[src] = true;

        for (auto neighbor : v[src]) {
            size  +=  return_component_size(neighbor );
        }
        return size;
    }
};



int main() {
    DFS dfs;
    char grid[6][5] = {
        ('w','L','w','w','w'),
        ('w','L','w','w','w'),
        ('w','w','w','L','w'),
        ('w','w','L','L','w'),
        ('L','w','w','L','L'),
        ('L','L','w','w','w')
    };
    



    return 0;
}
