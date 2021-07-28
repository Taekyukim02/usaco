#include <iostream>
#include <vector>

using namespace std;

vector <int> graph[30000];
bool damaged[30000];
bool visited[30000];
int cnt = 0;

void dfs(int n) {
	visited[n] = true;
	cnt++;
	for(int to : graph[n])
		if(!visited[to] && !damaged[to])
			dfs(to);
}

int main() {
	int P, C, N;
	cin >> P >> C >> N;
	for(int i=0; i<C; i++) {
		int a, b; 
		cin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}
	for(int i=0; i<N; i++) {
		int x;
		cin >> x;

		for(int to : graph[x-1])
			damaged[to] = true;
	}

	dfs(0);

	cout << P-cnt << endl;
	return 0;
}
