#include <iostream>
#include <fstream>
#define MAX_N 2005
#define MOD 1000000007ll

using namespace std;

int N;
char arr[MAX_N][MAX_N];
long long dp[MAX_N][MAX_N][2];
// R = [0], D = [1]

long long exp(long long a, long long b) {
	if(b == 0) return 1;
	if(b == 1) return a % MOD;
	if(b % 2 == 0) return exp(a*a%MOD, b/2);
	return a*exp(a*a%MOD, b/2)%MOD;
}

// a/b mod MOD
long long divide(long long a, long long b) {
	return a*exp(b, MOD-2) % MOD;
}

int main() {
	ifstream fin("sprinklers2.in");
	fin >> N;
	for(int i=0; i<N; i++)
		fin >> arr[i];
	fin.close();
	
	int c = 0;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			c += (arr[i][j] == 'W');
	
	dp[0][0][0] = exp(2, N*N-c);
	for(int i=1; i<=N; i++)
		dp[i][0][1] = dp[0][0][0];
	for(int j=1; j<=N; j++)
		dp[0][j][0] = dp[0][0][0];

	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++) {
			// R = [0]
			dp[i][j][0] = dp[i][j-1][0];
			if(arr[i-1][j-1] == '.')
				dp[i][j][0] += divide(dp[i][j-1][1], 2);
			dp[i][j][0] %= MOD;

			// D = [1]
			dp[i][j][1] = dp[i-1][j][1];
			if(arr[i-1][j-1] == '.')
				dp[i][j][1] += divide(dp[i-1][j][0], 2);
			dp[i][j][1] %= MOD;
		}
	
	long long ans = dp[N][N][0] + dp[N][N][1];
	ans %= MOD;

	ofstream fout ("sprinklers2.out");
	fout << ans << endl;
	fout.close();

/*
	for(int i=0; i<=N; i++)
		for(int j=0; j<=N; j++)
			cout << dp[i][j][0] << " \n"[j==N];

			cout << endl;
	for(int i=0; i<=N; i++)
		for(int j=0; j<=N; j++)
			cout << dp[i][j][1] << " \n"[j==N];
			*/
}
