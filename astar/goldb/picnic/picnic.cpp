#include <iostream>
#include <vector>
#define MAX_N 1000

using namespace std;

vector <int> path[MAX_N+1]; 	// path[x] contains y if there is a path from y to x
bool hasCow[MAX_N+1];
bool visited[MAX_N+1];

void dfs(int s) {
	if(visited[s]) return;
	visited[s] = true;

	for(int par : path[s])
		dfs(par);
	return;
}

int main() {
	// read input
	int K, N, M;
	cin >> K >> N >> M;

	for(int i=0; i<K; i++) {
		int a;
		cin >> a;
		hasCow[a] = true;
	}
	for(int i=0; i<M; i++) {
		int a, b;
		cin >> a >> b;
		path[b].push_back(a);
	}

	// iterate through every pasture
	int count = 0;
	for(int i=1; i<=N; i++) {
		for(int j=0; j<MAX_N+1; j++)
			visited[j] = 0;

		dfs(i);

		bool validBarn = true;
		for(int i=1; i<=N; i++)
			if(hasCow[i] && !visited[i])
				validBarn = false;

		if(validBarn)
			count++;
	}

	cout << count << endl;
	return 0;
}
