#include <iostream>

#define MAX_N 1000
#define MAX_C 10000

using namespace std;

long long N, W, B, X, C=0;
long long num[MAX_N+5], cost[MAX_N+5];
long long dp[MAX_N+5][MAX_C+5];
bool poss[MAX_N+5][MAX_C+5];

long long mymax (long long a, long long b) {
	return (a<b) ? b : a;
}
long long mymin (long long a, long long b) {
	return (a>b) ? b : a;
}

int main() {
	// read input
	cin >> N >> W >> B >> X;
	for(int i=1; i<=N; i++) {
		cin >> num[i];
		C += num[i];
	}
	for(int i=1; i<=N; i++)
		cin >> cost[i];
	
	// dp (base case)
	dp[0][0] = W-X;
	poss[0][0] = true;

	// dp 
	for(int i=1; i<=N; i++) {
		// simple dp
		for(int j=0; j<=C; j++) {
			for(int k=0; k <= num[i]; k++) {
				if(j-k < 0)
					break;

				if(poss[i-1][j-k] && mymin(X + dp[i-1][j-k], W+B*(j-k)) >= cost[i] * k) {
					poss[i][j] = true;
					dp[i][j] = mymax(dp[i][j], mymin(X + dp[i-1][j-k], W+B*(j-k)) - cost[i] * k);
				}
			}
			dp[i][j] = mymin(dp[i][j], W + B*j);
		}
	}

	// output answer
	long long ans = 0;
	for(int j=C; j>=0; j--)
		if(poss[N][j]) {
			ans = j;
			break;
		}
	
	cout << ans << endl;
}
