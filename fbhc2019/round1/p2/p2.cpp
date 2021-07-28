#include <iostream> 
#include <fstream>
#include <limits.h> 
#include <string.h> 
#include <queue> 
#include <algorithm>
#define MAX_N 55
#define ii pair<int, int>
#define pii pair<int, ii>
#define f first
#define s second

using namespace std; 

int T, N, H, graph[MAX_N][MAX_N];
pii X[MAX_N];
int remain[100005];

// Code for minimum-cut algorithm referenced from GeeksForGeeks

/* Returns true if there is a path from source 's' to sink 't' in 
  residual graph. Also fills parent[] to store the path */
int bfs(int rGraph[MAX_N][MAX_N], int s, int t, int parent[]) 
{ 
    // Create a visited array and mark all vertices as not visited 
    bool visited[MAX_N]; 
    memset(visited, 0, sizeof(visited)); 
  
    // Create a queue, enqueue source vertex and mark source vertex 
    // as visited 
    queue <int> q; 
    q.push(s); 
    visited[s] = true; 
    parent[s] = -1; 
  
    // Standard BFS Loop 
    while (!q.empty()) 
    { 
        int u = q.front(); 
        q.pop(); 
  
        for (int v=0; v<N+2; v++) 
        { 
            if (visited[v]==false && rGraph[u][v] > 0) 
            { 
                q.push(v); 
                parent[v] = u; 
                visited[v] = true; 
            } 
        } 
    } 
  
    // If we reached sink in BFS starting from source, then return 
    // true, else false 
    return (visited[t] == true); 
} 
  
// A DFS based function to find all reachable vertices from s.  The function 
// marks visited[i] as true if i is reachable from s.  The initial values in 
// visited[] must be false. We can also use BFS to find reachable vertices 
void dfs(int rGraph[MAX_N][MAX_N], int s, bool visited[]) 
{ 
    visited[s] = true; 
    for (int i = 0; i < N+2; i++) 
       if (rGraph[s][i] && !visited[i]) 
           dfs(rGraph, i, visited); 
} 
  
// Prints the minimum s-t cut 
int minCut(int graph[MAX_N][MAX_N], int s, int t) 
{ 
    int u, v; 
  
    // Create a residual graph and fill the residual graph with 
    // given capacities in the original graph as residual capacities 
    // in residual graph 
    int rGraph[MAX_N][MAX_N]; // rGraph[i][j] indicates residual capacity of edge i-j 
    for (u = 0; u < N+2; u++) 
        for (v = 0; v < N+2; v++) 
             rGraph[u][v] = graph[u][v]; 
  
    int parent[MAX_N];  // This array is filled by BFS and to store path 
  
    // Augment the flow while there is a path from source to sink 
    while (bfs(rGraph, s, t, parent)) 
    { 
        // Find minimum residual capacity of the edhes along the 
        // path filled by BFS. Or we can say find the maximum flow 
        // through the path found. 
        int path_flow = INT_MAX; 
        for (v=t; v!=s; v=parent[v]) 
        { 
            u = parent[v]; 
            path_flow = min(path_flow, rGraph[u][v]); 
        } 
  
        // update residual capacities of the edges and reverse edges 
        // along the path 
        for (v=t; v != s; v=parent[v]) 
        { 
            u = parent[v]; 
            rGraph[u][v] -= path_flow; 
            rGraph[v][u] += path_flow; 
        } 
    } 
  
    // Flow is maximum now, find vertices reachable from s 
    bool visited[MAX_N]; 
    memset(visited, false, sizeof(visited)); 
    dfs(rGraph, s, visited); 
  
    // Print all edges that are from a reachable vertex to 
    // non-reachable vertex in the original graph 
	int ans = 0;
    for (int i = 0; i < N+2; i++) 
      for (int j = 0; j < N+2; j++) 
         if (visited[i] && !visited[j] && graph[i][j]) 
              ans += graph[i][j]; 
  
    return ans; 
} 
  
int main() 
{ 
	ifstream fin ("p2.txt");
	ofstream fout("output.txt");

	fin >> T;
	//cin >> T;
	bool q = false;
	for(int i=1; i<=T; i++) {
		cout << "--------------- Running " << i << " --------------------" << endl;
		fin >> N >> H;
		//cin >> N >> H;
		for(int j=0; j<N; j++) {
			fin >> X[j].f >> X[j].s.f >> X[j].s.s;
			//cin >> X[j].f >> X[j].s.f >> X[j].s.s;
			if(X[j].s.f == 0 && X[j].s.s == H) {
				q = true;
			}
		}
		if(q) {q = false; fout << "Case #" << i << ": -1\n"; continue; }

		sort(X, X+N);

		for(int a=0; a<N+2; a++)
		for(int b=0; b<N+2; b++)
			graph[a][b] = 0;

		for(int a=0; a<N-1; a++) {
			for(int j=0; j<=H; j++) {
				if(j >= X[a].s.f && j < X[a].s.s)
					remain[j] = 1;
				else
					remain[j] = 0;
			}

			for(int b=a+1; b<N; b++) {
				int cnt = 0;
				for(int j=X[b].s.f; j < X[b].s.s; j++) {
					cnt += remain[j];
					remain[j] = 0;
				}
				graph[a][b] = graph[b][a] = cnt;
			}
		}
/*
		for(int a=0; a<N; a++)
			for(int b=0; b<N; b++)
				cout << graph[a][b] << " \n"[b==N-1];
				*/

		// combine source, combine sinks
		for(int a=0; a<N; a++) {
			if(X[a].s.f == 0) {
				for(int j=0; j<N; j++) {
					graph[N][j] += graph[a][j];
					graph[j][N] += graph[a][j];
					graph[a][j] = graph[j][a] = 0;
				}
			}
		}
		for(int a=0; a<N; a++) {
			if(X[a].s.s == H) {
				for(int j=0; j<N+1; j++) {
					graph[N+1][j] += graph[a][j];
					graph[j][N+1] += graph[a][j];
					graph[a][j] = graph[j][a] = 0;
				}
			}
		}

/*		cout << "after combining" << endl;
		for(int a=0; a<N+2; a++)
			for(int b=0; b<N+2; b++)
				cout << graph[a][b] << " \n"[b==N+1];
				*/

		// get minimum cut
		int ans = minCut(graph, N, N+1); 
		fout << "Case #" << i << ": " << ans << endl;
	}
  
    return 0; 
} 
