#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#define f first
#define s second

using namespace std;

typedef pair<int,int> ii;

int N, M, K;
vector <ii> graph[50001];
int hb[50001]; 
long long shPath[50001];

// executes the dijkstra algorithm from node N
void dijkstra() {
	bool visited[50001];
	for(int i=0; i<50001; i++)	visited[i] = false;
	priority_queue <ii> next;
	next.push( ii(0, N) );

	while(!next.empty()) {
		ii x = next.top();
		next.pop();

		if(visited[x.s])
			continue;
		visited[x.s] = true;

		// update shPath[]
		shPath[x.s] = -x.f;

		// extend to neighbors if not visited
		for(ii n : graph[x.s])
			if(!visited[n.f])
				next.push( ii(x.f-n.s, n.f) );
	}
}

int main() {
	// read input
	ifstream fin ("dining.in");
	fin >> N >> M >> K;
	for(int i=0; i<M; i++) {
		int a, b, c;
		fin >> a >> b >> c;
		graph[a].push_back( ii(b,c) );
		graph[b].push_back( ii(a,c) );
	}
	for(int i=0; i<K; i++) {
		int a, b;
		fin >> a >> b;
		hb[a] += b;
	}
	fin.close();

	// dijkstra for shortest path from node N
	dijkstra();

	// bfs from every single haybale
	bool mealable[50001];
	bool visited[50001];
	for(int i=0; i<50001; i++) {
		mealable[i] = false;			// basically the visited array
		visited[i] = false;
	}
	priority_queue <ii> pq;									// ii.f is max tolerance | ii.s is node ID
	for(int i=1; i<=N; i++)
		if(hb[i] > 0)
			pq.push( ii(hb[i]-shPath[i], i) );

	while(!pq.empty()) {
		ii x = pq.top();
		pq.pop();

		if(visited[x.s])
			continue;

		if(x.f >= -shPath[x.s])
			mealable[x.s] = 1;
		else
			mealable[x.s] = 0;
		visited[x.s] = true;

		// extend to neighbors
		for(ii n : graph[x.s]) {
			if(!visited[n.f])
				pq.push( ii(x.f-n.s, n.f) );
		}
	}

	// print N-1 lines for mealable/unmealable cows
	ofstream fout ("dining.out");
	if(mealable[N])
		for(int i=1; i<N; i++)
			fout << 1 << endl;
	else
		for(int i=1; i<N; i++)
			fout << mealable[i] << endl;
	fout.close();

	return 0;
}
