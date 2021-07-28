#include <iostream>
#include <vector>

using namespace std;

int N, L[100];
vector <int> graph[100][2];

int bestLen = 987654321;

// find loops
void dfs(int start, int node, int par, int currLen) {
	if(currLen >= bestLen)
		return;
	
	// check if looped
	if(par != -1 && start == node) {
		bestLen = currLen;
		return;
	}

	// find side to skip
	int skip = -1;
	for(int i : graph[node][0])
		if(i == par)
			skip = 0;
	for(int i : graph[node][1])
		if(i == par)
			skip = 1;
	
	// dfs from each side != skip
	for(int i=0; i<2; i++) {
		if(i != skip) {
			for(int to : graph[node][i]) {
				dfs(start, to, node, currLen + L[node]);
			}
		}
	}

	return;
}

int main() {
	// read input
	cin >> N;
	for(int i=0; i<N; i++) {
		int s, m1, m2;
		cin >> s;
		cin >> L[s-1];
		cin >> m1 >> m2;
		for(int j=0; j<m1; j++) {
			int to;
			cin >> to;
			graph[s-1][0].push_back(to-1);
		}
		for(int j=0; j<m2; j++) {
			int to;
			cin >> to;
			graph[s-1][1].push_back(to-1);
		}
	}

	// start from every edge and try to dfs until reach a loop
	for(int i=0; i<N; i++) {
		dfs(i, i, -1, 0);
	}

	// output answer
	cout << bestLen << endl;

	return 0;
}
