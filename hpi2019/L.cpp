#include <iostream>
#include <vector>

#define MAX_N 2005
#define INF 10000000000

using namespace std;

typedef pair<int, int> ii;

int visited[MAX_N], dist[MAX_N];
vector <ii> G[MAX_N];

int N, M;

int main() {
	cin >> N >> M;
	for(int i=0; i<M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		G[a-1].push_back( ii(b-1, c));
		G[b-1].push_back( ii(a-1, c));
	}

	for(int i=0; i<MAX_N; i++) {
		visited[i] = false;
		dist = INF;
	}

	visited[0] = true;
	dist[0] = 0;
	int cnt = 1;
	while(cnt < N) {
		int idx = -1;
		for(int i=0; i<N; i++) {
			if(!visited[i] && (idx == -1 || dist[i] < dist[idx]) ) {
				idx = i;
			}

			if(dist[idx] == INF) {
				cout <<
			}
		}
	}
}
