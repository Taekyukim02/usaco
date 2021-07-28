#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, a[200000], root;
vector <int> graph[200000];
vector <int> order;
long long sum[200000];

void dfs(int n, int p) {
	for(int to : graph[n])
		if(to != p)
			dfs(to, n);
	order.push_back(n);
}

void createDpOrder() {
	// root a random node
	root = (rand()%N);
	dfs(root, -1);
}

void createSubsum() {
	for(int i=0; i<N; i++) {
		int v = order[i];
		sum[v] = a[v];

		for(int n : graph[v])
			if(sum[n] > 0)
				sum[v] += sum[n];
	}
}

long long solve() {
	long long cost[200000];
	for(int i=0; i<N; i++)	cost[i] = 0;

	// calculate cost[root]
	bool visited[200000];
	for(int i=0; i<N; i++) visited[i] = false;
	queue <pair<int,int> > bfs;
	bfs.emplace(root, 0);
	while(!bfs.empty()) {
		pair<int,int> x = bfs.front();
		bfs.pop();

		if(visited[x.first]) continue;
		visited[x.first] = true;

		cost[root] += x.second * a[x.first];
		for(int n : graph[x.first])
			if(!visited[n])
				bfs.emplace(n, x.second+1);
	}

	long long ans = cost[root];
	for(int i=N-2; i>=0; i--) {
		int v = order[i];
		int n = -1;
		for(int to : graph[v])
			if(cost[to] > 0)
				n = to;

		cost[v] = cost[n] - sum[v]
					+ (sum[root] - sum[v]);

		if(ans < cost[v]) ans = cost[v];
	}

	return ans;
}

int main() {
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> a[i];
	for(int i=0; i<N-1; i++) {
		int x, y;
		cin >> x >> y;
		graph[x-1].push_back(y-1);
		graph[y-1].push_back(x-1);
	}

	// root the graph
	createDpOrder();
	
	// get sum of vertex weights for each subtree
	createSubsum();

	// dp on the order
	cout << solve() << endl;
}
