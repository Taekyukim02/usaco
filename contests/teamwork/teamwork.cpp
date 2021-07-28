#include <iostream>
#include <fstream>

using namespace std;

int N, K;
int skill[10001];

int main() {
	// read input
	ifstream fin ("teamwork.in");
	fin >> N >> K;
	for(int i=1; i<=N; i++)
		fin >> skill[i];
	fin.close();

	// dp
	long long dp[10001];
	for(int i=0; i<=10000; i++) dp[i] = 0;
	dp[0] = 0;

	for(int i=1; i<=N; i++) {
		int maxS = skill[i];
		for(int j=i-1; j>=i-K && j>=0; j--) {
			maxS = max(maxS, skill[j+1]);
			dp[i] = max(dp[i], dp[j] + (i-j) * maxS);
		}
	}

	// print output
	ofstream fout ("teamwork.out");
	fout << dp[N] << endl;
	fout.close();

	return 0;
}
