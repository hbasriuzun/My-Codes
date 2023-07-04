#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

class Graph {
	int V; 

	
	list<pair<int, int> >* adj;

public:
	Graph(int V); 

	void addEdge(int u, int v, int w);

	void shortestPath(int s);
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

void Graph::shortestPath(int src)
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

	printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
}

int main()
{
	int row,col;
	cin>>row>>col;
	int arr[row+2][col+2];
	Graph g(row*col);
	for(int i=0;i<col+2;i++){
		arr[i][0]=0;
		arr[i][col+2]=0;
	}
	for(int i=0;i<row+2;i++){
		arr[0][i]=0;
		arr[row+2][i]=0;
	}

	for(int i=1;i<row+1;i++){
		for(int j=1;j<col+1;j++){
			cin>>arr[i][j];
		}
	}

	for(int i=1;i<row+1;i++){
		for(int j=1;j<col+1;j++){
			if(arr[i][j] != 0){
				if(arr[i-1][j] != 0){
					g.addEdge(arr[i][j],arr[i-1][j],abs(arr[i][j]-arr[i-1][j]));
				}
				if(arr[i+1][j] != 0){
					g.addEdge(arr[i][j],arr[i+1][j],abs(arr[i][j]-arr[i+1][j]));
				}
				if(arr[i][j-1] != 0){
					g.addEdge(arr[i][j],arr[i][j-1],abs(arr[i][j]-arr[i][j-1]));
				}
				if(arr[i][j+1] != 0){
					g.addEdge(arr[i][j],arr[i][j+1],abs(arr[i][j]-arr[i][j+1]));
				}
				
			}
		}
	}

	


	g.addEdge(0, 1, 2);
	g.addEdge(0, 2, 6);
	g.addEdge(1, 3, 5);
	g.addEdge(2, 3, 8);
	g.addEdge(3, 4, 10);
	g.addEdge(3, 5, 15);
	g.addEdge(4, 6, 2);
	g.addEdge(5, 6, 6);
	g.shortestPath(0);

	return 0;
}
