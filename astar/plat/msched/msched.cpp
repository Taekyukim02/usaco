#include <iostream>
#include <vector>

using namespace std;

int N, M, T[10001];
vector <int> graph[10001];
long long dp[10001];

long long dfs(int num) {
	if(dp[num] != 0)
		return dp[num];
	
	long long child = 0;
	for(int i : graph[num])
		child = max(child, dfs(i));
	
	return dp[num] = (child + T[num]);
}

int main() {
	cin >> N >> M;
	for(int i=1; i<=N; i++)
		cin >> T[i];
	for(int i=0; i<M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	for(int i=1; i<=N; i++)
		graph[0].push_back(i);
	
	for(int i=0; i<=N; i++)
		dp[i] = 0;

	cout << dfs(0) << endl;
}
