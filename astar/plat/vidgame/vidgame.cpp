#include <iostream>

using namespace std;

typedef pair<int,int> ii;

int N, V;
int p[50];
vector <ii> g[50];

int main() {
	cin >> N >> V;
	for(int i=0; i<N; i++) {
		cin >> p[i];
		cin >> n;
		for(int j=0; j<n; j++) {
			cin >> a >> b;
			g[i].emplace_back(a, b);
	}

	long long ksack[50][100001];
	for(int i=0; i<N; i++) {
		for(int j=0; j<=V; j++) ksack[i][j] = 0;

		for(ii x : g[i]) {
			for(int j=V; j-x.first>=0; j--)
				if(ksack[i][j] < ksack[i][j-x.first] + x.second)
					ksack[i][j] = ksack[i][j-x.first] + x.second;
		}
	}

	long long dp[100001];
	for(int i=0; i<100001; i++)
		dp[i] = 0;

	for(int i=0; i<N; i++) {
		for(int j=V; j+p[i]>=0; j--) {
			if(dp[j] < dp[j-p[i]]
		}
	}
	
	cout << dp[V] << endl;
}
