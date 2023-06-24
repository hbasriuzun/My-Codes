#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <list>

#define endl "\n"
const int N = 1e5+5;

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

#define INF 0x3f3f3f3f

typedef pair<int, int> iPair;


class Graph {
	int V; 
	list<pair<int, int> >* adj;

public:
	Graph(int V); 

	void addEdge(int u, int v, int w);

	void shortestPath(int s, int d);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(int src, int des)
{

	priority_queue<iPair, vector<iPair>, greater<iPair> >
		pq;


	vector<int> dist(V, INF);


	pq.push(make_pair(0, src));
	dist[src] = 0;


	while (!pq.empty()) {

		int u = pq.top().second;
		pq.pop();


		list<pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i) {
			int v = (*i).first;
			int weight = (*i).second;

			if (dist[v] > dist[u] + weight) {
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}

	cout << dist[des] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	int node,coridor;
    cin >> node >> coridor;
    int Roka,Utku;
    cin >> Roka >> Utku;

	Graph g(node+1);
    int p,j,l;

	for(int i=1; i<=node; i++){
        cin >> p >> j;

        for(int k=0; k<j; k++){
            cin >> l;
            g.addEdge(p, l, 1);
        }
    }
    g.shortestPath(Roka, Utku);

	return 0;
}
