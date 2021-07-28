/*
ID: taekyuk1
TASK: nuggets
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int N, nug[10];

int main() {
	ifstream fin ("nuggets.in");
	fin >> N;
	for(int i=0; i<N; i++)
		fin >> nug[i];
	fin.close();

	int g = nug[0];
	for(int i=0; i<N; i++)
		g = __gcd(g, nug[i]);
	if(g > 1) { 	// not bounded
		ofstream fout ("nuggets.out");
		fout << 0 << endl;
		fout.close();
	}

	int maxNug = 0;
	for(int i=0; i<N; i++)
		maxNug = max(maxNug, 

	bool dp[257][2];
	for(int i=0; i<=maxNug; i++)
		dp[i][0] = dp[i][1] = 0;
	for(int i=0; i<N; i++)
		dp[nug[i]][0] = 1;
	int mul=0;
	int minR=0;
	bool changed = false;
	do {
		changed = false;
		mul++;

		for(int i=0; i<maxNug; i++)
		
	} while (changed);

	int ans = mul*maxNug + minR;

	ofstream fout ("nuggets.out");
	fout << ans << endl;
	fout.close();
}
