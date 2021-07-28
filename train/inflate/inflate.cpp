/*
ID: taekyuk1
TASK: inflate
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int M, N, p[10000], m[10000];
	ifstream fin ("inflate.in");
	fin >> M >> N;
	for(int i=0; i<N; i++)
		fin >> p[i] >> m[i];
	fin.close();

	int dp[10001];
	for(int i=0; i<=M; i++) dp[i] = 0;

	for(int i=0; i<N; i++) {
		for(int j=0; j+m[i]<=M; j++) {
			dp[j+m[i]] = max(max(dp[j+m[i]], dp[j+m[i]-1]), dp[j] + p[i]);
		}
	}

	ofstream fout ("inflate.out");
	fout << dp[M] << endl;
	fout.close();
}
