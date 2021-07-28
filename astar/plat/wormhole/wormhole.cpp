#include <iostream>
#include <vector>
#define f first
#define s second

using namespace std;

typedef pair<int,int> ii;

int F, N, M, W;
vector <ii> graph[505];

// check for negative cycle
bool negCycle() {
	int dist[505];

	// start from node '0'
	for(int i=1; i<=N; i++)
		dist[i] = 0;
	
	// relax distance N-1 times
	for(int i=0; i<N-1; i++) {
		for(int j=1; j<=N; j++) {
			for(ii to : graph[j]) {
				if(dist[to.f] > dist[j] + to.s)
					dist[to.f] = dist[j] + to.s;
			}
		}
	}

	// check N'th relax
	for(int j=1; j<=N; j++) {
		for(ii to : graph[j]) {
			if(dist[to.f] > dist[j] + to.s)
				return true;
		}
	}
	return false;
}

int main() {
	cin >> F;
	for(int i=0; i<F; i++) {
		cin >> N >> M >> W;
		for(int j=0; j<505; j++)
			graph[j].clear();

		for(int j=0; j<M; j++) {
			int a, b, c;
			cin >> a >> b >> c;
			graph[a].push_back(ii(b, c));
			graph[b].push_back(ii(a, c));
		}
		for(int j=0; j<W; j++) {
			int a, b, c;
			cin >> a >> b >> c;
			graph[a].push_back(ii(b, -c));
		}

		if(negCycle())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
