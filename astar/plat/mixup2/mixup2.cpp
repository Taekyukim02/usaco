#include <iostream>

#define MAX_N 16

using namespace std;

int N, K, S[MAX_N];
int dp[MAX_N][(1<<MAX_N)];

int main() {
	cin >> N >> K;
	for(int i=0; i<N; i++)
		cin >> S[i];
	
	// dp
	for(int i=0; i<N; i++)
		dp[i][(1<<i)] = 1;

	for(int i=0; i<(1<<N); i++) {
		for(int j=0; j<N; j++) {
			if(dp[j][i] > 0)
				continue;

			dp[j][i] = 0;

			// invalid i, j
			if((i & (1<<j)) == 0)
				continue;

			for(int k=0; k<N; k++) {
				if(j != k && abs(S[j] - S[k]) > K) {
					dp[j][i] += dp[k][i ^ (1<<j)];	
				}
			}
		}
	}

	int ans = 0;
	for(int i=0; i<N; i++) {
		ans += dp[i][(1<<N) - 1];
	}
	cout << ans << endl;
}
