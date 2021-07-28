#include <iostream>
#include <vector>
#include <queue>
#define INF 10000000
#define f first
#define s second

using namespace std;

typedef pair<int,int> ii;

int main() {
	int V, E, S;
	cin >> V >> E >> S;
	
	vector <ii> graph[50000];
	for(int i=0; i<E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a-1].push_back( ii(b-1, c) );
		graph[b-1].push_back( ii(a-1, c) );
	}

	// search
	bool visited[50000];
	for(int i=0; i<V; i++) visited[i] = false;
	int dist[50000];
	for(int i=0; i<V; i++) dist[i] = -1;

	priority_queue <ii> pq;
	dist[S-1] = 0;
	pq.push( ii(0, S-1) );

	while(!pq.empty()) {
		ii a = pq.top();
		pq.pop();

		if(visited[a.s]) continue;
		visited[a.s] = true;

		dist[a.s] = (-a.f);

		for(ii i : graph[a.s])
			pq.push(ii (-i.s+a.f, i.f));
	}

	// print output
	for(int i=0; i<V; i++)
		cout << dist[i] << endl;
	return 0;
}
