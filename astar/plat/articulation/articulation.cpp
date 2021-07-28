#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

int N, M;
vector <int> graph[100000];
vector <int> child[100000];

int T[100000], visited[100000], low[100000];
bool isArt[100000];
int n=0;

void dfs(int cur, int pre) {
	visited[cur] = 1;
	T[cur] = n++;
	low[cur] = T[cur];
	for(int nxt : graph[cur]) {
		if(nxt == pre)
			continue;
		if(low[nxt] != INF) 	// visited
			low[cur] = min(low[cur], T[nxt]);
		else {
			dfs(nxt, cur);
			child[cur].push_back(nxt);
			low[cur] = min(low[cur], low[nxt]);
		}
	}
}

int main() {
	cin >> N >> M;
	for(int i=0; i<M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}

	for(int i=0; i<N; i++) {
		low[i] = T[i] = INF;
	}
	for(int root=0; root<N; root++) {
		n=0;
		if(visited[root])
			continue;

		dfs(root, -1);
			
		for(int a=0; a<N; a++) {
			if(visited[a] != 1) continue;
			if(a==root) {
				if(child[a].size() > 1) {
					isArt[a] = true;
	//				cout << root << " is articulation point" << endl;
				}
				visited[a] = 2;
				continue;
			}
			for(int nxt : child[a])
				if(T[a] < T[nxt] && low[nxt] >= T[a])
						isArt[a] = true;

			visited[a] = 2;
		}
	}
	
	/*
	for(int i=0; i<N; i++)
		cout << T[i] << " \n"[i==N-1];
	for(int i=0; i<N; i++)
		cout << low[i] << " \n"[i==N-1];
	for(int i=0; i<N; i++)
		cout << isArt[i] << " \n"[i==N-1];
	for(int i=0; i<N; i++) {
		cout << i << ":  ";
		for(int nxt : child[i])
			cout << nxt << " ";
		cout << endl;
	}
	*/
	int cnt = 0;
	for(int i=0; i<N; i++)
		if(isArt[i])
			cnt++;
	cout << cnt << endl;
}
