#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector <int> graph[100000];
int val[100000];
int dp[100000][22];

int main() {
	cin >> N >> K;
	for(int i=0; i<N-1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}
	for(int i=0; i<N; i++)
		cin >> val[i];
	
	for(int i=0; i<N; i++) {
		dp[i][0] = 0;
		dp[i][1] = val[i];
	}
	for(int i=2; i<=K+1; i++) {
		for(int j=0; j<N; j++) {
			dp[j][i] = 0;
			for(auto to : graph[j])
				dp[j][i] += dp[to][i-1];

			if(i>2)
				dp[j][i] -= dp[j][i-2] * (graph[j].size()-1);
			else
				dp[j][i] += val[j];
		}
	}

	for(int i=0; i<N; i++)
		cout << dp[i][K+1] << " \n";
}
