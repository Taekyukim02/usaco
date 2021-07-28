#include <iostream>
#include <algorithm>
#define MAX_N 2000

using namespace std;

long long dp[MAX_N+1][MAX_N+1];
int main()
{
	int N;
	cin >> N;
	
	int C[MAX_N];
	long long suf[MAX_N];
	for(int i=0; i<N; i++)
		cin >> C[i];
	
	// calcuate suffix array
	suf[N-1] = C[N-1];
	for(int i=N-2; i>=0; i--)
		suf[i] = suf[i+1] + C[i];

	// dp
	for(int j=1; j<=MAX_N; j++) {
		dp[N-1][j] = C[N-1];
		dp[N][j] = 0;
	}

	for(int i=N-2; i>=0; i--) {
		for(int j=1; j<=i+2; j++) {
			long long c = 10000000;
			if(i+j<=N)
				c = dp[i+j][min(2*j,N)];
			if(j>1)
				dp[i][j] = max(dp[i][j-1], suf[i]-c);
			else
				dp[i][j] = suf[i]-c;
		}
	}
	/*
	for(int i=0; i<=N; i++) {
		for(int j=1; j<20; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
	*/

	cout << max(dp[0][1], dp[0][2]) << endl;
	return 0;
}
