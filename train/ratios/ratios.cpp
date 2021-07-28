/*
ID: taekyuk1
TASK: ratios
LANG: C++
*/
#include <iostream>
#include <fstream>
#define INF 1000000000

using namespace std;

int X[4], Y[4], Z[4];
int cnt[4] = {0, 0, 0, 0};
int m;

bool dfs(int x, int y, int z, int prev, int n, int d) {
	if(n==d) {
		if(X[0]) m = x/X[0];
		else if(Y[0]) m = y/Y[0];
		else if(Z[0]) m = z/Z[0];

		if(X[0]*m == x && Y[0]*m == y && Z[0]*m == z)
			return true;
		else
			return false;
	}
	
	// recurse down
	for(; prev<4; prev++) {
		if(cnt[prev]+1 == 100) continue;

		cnt[prev]++;
		if(dfs(x+X[prev], y+Y[prev], z+Z[prev], prev, n+1, d))
			return true;
		cnt[prev]--;
	}
	return false;
}

int main() {
	ifstream fin ("ratios.in");
	for(int i=0; i<4; i++)
		fin >> X[i] >> Y[i] >> Z[i];
	fin.close();

	int depth;
	for(depth=1; depth<=300; depth++)
		if(dfs(0, 0, 0, 1, 0, depth))
			break;

	ofstream fout ("ratios.out");
	if(depth==301)
		fout << "NONE" << endl;
	else
		fout << cnt[1] << " " << cnt[2] << " " << cnt[3] << " " << m << endl;
	fout.close();
	
	return 0;
}
