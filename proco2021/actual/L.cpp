#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

// Code from https://www.geeksforgeeks.org/find-a-mother-vertex-in-a-graph/
// For finding mother vertex

class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // adjacency lists
 
    // A recursive function to print DFS starting from v
    void DFSUtil(int v, vector<bool> &visited);
public:
    Graph(int V);
    void addEdge(int v, int w);
    int findMother();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
// A recursive function to print DFS starting from v
void Graph::DFSUtil(int v, vector<bool> &visited)
{
    // Mark the current node as visited and print it
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
// Returns a mother vertex if exists. Otherwise returns -1
int Graph::findMother()
{
    // visited[] is used for DFS. Initially all are
    // initialized as not visited
    vector <bool> visited(V, false);
 
    // To store last finished vertex (or mother vertex)
    int v = 0;
 
    // Do a DFS traversal and find the last finished
    // vertex 
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            DFSUtil(i, visited);
            v = i;
        }
    }
 
    // If there exist mother vertex (or vetices) in given
    // graph, then v must be one (or one of them)
 
    // Now check if v is actually a mother vertex (or graph
    // has a mother vertex).  We basically check if every vertex
    // is reachable from v or not.
 
    // Reset all values in visited[] as false and do
    // DFS beginning from v to check if all vertices are
    // reachable from it or not.
    fill(visited.begin(), visited.end(), false);
    DFSUtil(v, visited);
    for (int i=0; i<V; i++)
        if (visited[i] == false)
            return -1;
 
    return v;
}
 
// Driver program to test above functions
int main()
{
	long long N, M;
	cin >> N >> M;
    Graph g(N);
    Graph h(N);
	for(int i=0; i<M; i++) {
		long long x, y;
		cin >> x >> y;
		g.addEdge(x-1, y-1);
		h.addEdge(y-1, x-1);
	}

	int ans = 2;
	if(g.findMother() == -1)
		ans --;
	if(h.findMother() == -1)
		ans --;
 
 	cout << ans << endl;
    return 0;
}
