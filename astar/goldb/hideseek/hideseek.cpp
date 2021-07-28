#include <iostream>
#include <queue>
#include <vector>
#define MAX_N 20000

using namespace std;

typedef pair<int,int> ii;

vector <int> neighbor[MAX_N+1];

int minDist[MAX_N+1];

void traverse() {
	bool visited[MAX_N];
	for(int i=0; i<MAX_N+1; i++) visited[i] = false;

	queue <ii> bfs;
	bfs.emplace(1 ,0);
	while(!bfs.empty()) {
		ii x = bfs.front();
		bfs.pop();
		if(visited[x.first]) continue;
		visited[x.first] = true;

		if(minDist[x.first] == 0)
			minDist[x.first] = x.second;
		else if(minDist[x.first] > x.second)
			minDist[x.first] = x.second;

		for(int y : neighbor[x.first])
			if(!visited[y]) {
				bfs.emplace(y, x.second+1);
			}
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	for(int i=0; i<M; i++) {
		int a, b;
		cin >> a >> b;
		neighbor[a].push_back(b);
		neighbor[b].push_back(a);
	}

	traverse();

	int index = 0;
	int dist = 0;
	int numBarn = 0;
	for(int i=1; i<=N; i++) {
		if(dist == minDist[i]) {
			numBarn++;
		} else if(dist < minDist[i]) {
			index = i;
			dist = minDist[i];
			numBarn = 1;
		}
	}
	cout << index << " " << dist << " " << numBarn << endl;
}
