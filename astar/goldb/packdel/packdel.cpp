#include <iostream>
#include <vector>
#include <queue>
#define INF 10000000
#define f first
#define s second

using namespace std;

typedef pair<int,int> ii;

int main() {
	int V, E;
	cin >> V >> E;
	
	vector <ii> graph[50000];
	for(int i=0; i<E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		bool encountered = false;
		for(auto it = graph[a-1].begin(); it!=graph[a-1].end(); it++) {
			if(it->f == b-1) {
				encountered = true;
				if(it->s > c) {
					graph[a-1].erase(it);
					graph[a-1].push_back( ii(b-1, c) );
				}
				break;
			}
		}
		if(!encountered)
			graph[a-1].push_back( ii(b-1, c) );
		
		encountered = false;
		for(auto it = graph[b-1].begin(); it!=graph[b-1].end(); it++) {
			if(it->f == a-1) {
				encountered = true;
				if(it->s > c) {
					graph[b-1].erase(it);
					graph[b-1].push_back( ii(a-1, c) );
				}
				break;
			}
		}
		if(!encountered)
			graph[b-1].push_back( ii(a-1, c) );
	}

	// search
	bool visited[50000];
	for(int i=0; i<V; i++) visited[i] = false;
	int dist[50000];
	for(int i=0; i<V; i++) dist[i] = -1;

	priority_queue <ii> pq;
	dist[0] = 0;
	pq.push( ii(0, 0) );

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
	cout << dist[V-1] << endl;
	return 0;

}
