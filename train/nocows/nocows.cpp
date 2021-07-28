/*
ID: taekyuk1
TASK: nocows
LANG: C++
*/
#include <iostream>
#include <fstream>
#define MOD 9901

using namespace std;

int main() {
	ifstream fin ("nocows.in");
	int N, K;
	fin >> N >> K;
	fin.close();

	int dp[200][100];
	for(int i=0; i<200; i++)
		for(int j=0; j<100; j++)
			dp[i][j] = 0;
	
	dp[0][0] = 1;
	dp[1][1] = 1;

	for(int i=2; i<=N; i++) {
		for(int j=2; j<=i/2+2 && j<=K; j++) {
			for(int k=1; k<i-1; k++) {
				for(int l=1; l<j-1; l++) {
					dp[i][j] = (dp[i][j] + (dp[k][l]*dp[i-k-1][j-1] % MOD )) % MOD;
					dp[i][j] = (dp[i][j] + (dp[k][j-1]*dp[i-k-1][l] % MOD )) % MOD;
				}
				dp[i][j] = (dp[i][j] + (dp[k][j-1]*dp[i-k-1][j-1] % MOD )) % MOD;
			}
		}
	}
	
	ofstream fout ("nocows.out");
	fout << dp[N][K] << endl;
	fout.close();

	return 0;
}
