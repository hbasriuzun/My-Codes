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

template <typename T> class BFS {
public:
    vector<vector<T>> v;
    map<T, bool> exploerer;
    ll nodes_number;

    void get_graph() {
        T edges_number;
        cin >> nodes_number >> edges_number;
        v.resize(nodes_number + 1);
        for(ll i = 0; i < edges_number; i++){
            T a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
    }

    ll shortest_path(T src, T des) {
        get_graph();

        queue <pair<T,ll> frontier;
        frontier.push(make_pair(src,0));
        exploerer[src] = true;


        while(!frontier.empty()){
            pair<T,ll> current = frontier.front();
            frontier.pop();

            if (current.first == des)
                return current.second;

            for(auto neighbor : v[current.first]){
                if(!exploerer[neighbor]){
                    frontier.push(make_pair(neighbor,current.second+1));
                    exploerer[neighbor] = true;
                }
            }
            
        }
        return -1;
    }
};

int main() {
    BFS <char> bfs;
    bfs.shortest_path();
    
    



    return 0;
}
