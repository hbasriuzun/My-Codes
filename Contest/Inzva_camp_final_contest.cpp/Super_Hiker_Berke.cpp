#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <list>

#define endl "\n"
const int N = 1e5+5;

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

#define INF 0x3f3f3f3f

typedef pair<int, int> iPair;
typedef struct node{
    int x;
    int y;
}node;

class Graph {
	int V; 

	
	map<node,vector<pair<node, int> >> adj;

public:
	Graph(int V); 

	void addEdge(node u, node v, int w);

	void shortestPath(node s,node d);
};

Graph::Graph(int V)
{
	this->V = V;

}

void Graph::addEdge(node u, node v, int w)
{

	adj[u].push_back ( make_pair(v, w));
	adj[v].push_back( make_pair(u, w));
}

void Graph::shortestPath(node src,node dst)
{

	priority_queue<pair<node, int>, vector<pair<node, int>>, greater<pair<node, int>> > pq;


	vector<node> dist(V, {INF,INF});
    
    node tmp;
    tmp.x = 0;
    tmp.y = 0;
	pq.push(make_pair(node, src));
	dist[src] = 0;


	while (!pq.empty()) {

		int u = pq.top().second;
		pq.pop();

        
		for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {

			int v = (*i).first;
			int weight = (*i).second;

			if (dist[v] > dist[u] + weight) {
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}

	cout << dist[dst] << endl;

}



int main()
{
	int row,col;
	cin>>row>>col;
	int arr[row+2][col+2];
	Graph g(row*col);
	for(int i=0;i<row+2;i++){
		arr[i][0]=0;
		arr[i][col+1]=0;
	}
	for(int i=0;i<col+2;i++){
		arr[0][i]=0;
		arr[row+1][i]=0;
	}

	for(int i=1;i<row+1;i++){
		for(int j=1;j<col+1;j++){
			cin>>arr[i][j];
		}
	}

	for(int i=1;i<row+1;i++){
		for(int j=1;j<col+1;j++){
			if(arr[i][j] != 0){
                node n,m;;
                n.x = i;
                n.y = j;
				if(arr[i-1][j] != 0){
                    m.x = i-1;
                    m.y = j;
					g.addEdge(n,m,abs(arr[i][j]-arr[i-1][j]));
				}
				if(arr[i+1][j] != 0){
                    m.x = i+1;
                    m.y = j;
					g.addEdge(n,m,abs(arr[i][j]-arr[i+1][j]));
				}
				if(arr[i][j-1] != 0){
                    m.x = i;
                    m.y = j-1;
                    g.addEdge(n,m,abs(arr[i][j]-arr[i][j-1]));
				}
				if(arr[i][j+1] != 0){
                    m.x = i;
                    m.y = j+1;
                    g.addEdge(n,m,abs(arr[i][j]-arr[i][j+1]));
				}
				
			}
		}
	}

	
    int srcx = 0,srcy = 0,dstx = 0,dsty = 0;
    cin >> srcx >> srcy >> dstx >> dsty;

	
	g.shortestPath(arr[srcx][srcy],arr[dstx][dsty]);

	return 0;
}
