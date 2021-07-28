/*
ID: taekyuk1
TASK: butter
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define f first
#define s second
#define INF 1000000000

using namespace std;

typedef pair<int,int> ii;

int N, P, C;
int cows[500];
vector <ii> graph[800];
int totSum[800];
bool updated[800];

int main() {
	ifstream fin ("butter.in");
	fin >> N >> P >> C;
	for(int i=0; i<N; i++) {
		fin >> cows[i];
		cows[i]--;
	}
	for(int i=0; i<C; i++) {
		int a, b, c;
		fin >> a >> b >> c;
		graph[a-1].push_back( ii(b-1, c));
		graph[b-1].push_back( ii(a-1, c));
	}
	fin.close();

	// dijkstra frome each cow
	for(int i=0; i<N; i++) {
		bool visited[800];
		for(int i=0; i<800; i++) visited[i] = false;

		priority_queue <ii> Q;
		Q.push( ii(0, cows[i]) );
		while(!Q.empty()) {
			ii x = Q.top();
			Q.pop();

			if(visited[x.s])
				continue;
			visited[x.s] = true;
			totSum[x.s] += (-x.f);
			updated[x.s] = true;

			for(ii to : graph[x.s]) {
				Q.push( ii(x.f-to.s, to.f) );
			}
		}
	}

	// find best pasture for butter
	int best = INF;
	for(int i=0; i<800; i++) {
		if(updated[i] && best > totSum[i])
			best = totSum[i];
	}

	ofstream fout ("butter.out");
	fout << best << endl;
	fout.close();

	return 0;
}
