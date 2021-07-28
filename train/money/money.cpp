/*
ID: taekyuk1
TASK: money
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin ("money.in");
	int N, V;
	fin >> V >> N;
	long long c[25];
	for(int i=0; i<V; i++)
		fin >> c[i];
	fin.close();

	long long dp[10001];
	for(int i=0; i<=N; i++)
		dp[i] = 0;
	dp[0] = 1;

	for(int i=0; i<V; i++)
		for(int j=0; c[i]+j<=N; j++)
			dp[c[i]+j] += dp[j];

	ofstream fout ("money.out");
	fout << dp[N] << endl;
	fout.close();
}
