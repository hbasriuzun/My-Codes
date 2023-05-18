#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;


bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
    if(n == 1) return true;

    unordered_map <int,vector<int>> adj(n);

    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map <int,bool> explored(n);
    queue <int> frontier;
    frontier.push(source);
    explored[source] = true;

    while (!frontier.empty()){
        int node = frontier.front();
        frontier.pop();

        for(auto it:adj[node]){
            
            if(it == destination) return true;
            else if(explored[it] != 1){
                explored[it] = 1;
                frontier.push(it);
            }

        }
    

    }
    return false;
}

    int main(){
        int n = 6;
        vector<vector<int>> edges = {{0,1},{0,2},{3,5},{5,4},{4,3}};
        int source = 0;
        int destination = 5;
        cout << validPath(n, edges, source, destination) << endl;
        return 0;
    }
