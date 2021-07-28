#include <iostream>
#include <fstream>
#define f first
#define s second
#define INF 1000000000ll

using namespace std;

typedef pair<int,int> ii;

int H, G;
ii h[1001], g[1001];

long long calculate(ii a, ii b) {
	if(a == ii(-1,-1) || b == ii(-1,-1))
		return INF;
	return (a.s-b.s)*(a.s-b.s)+(a.f-b.f)*(a.f-b.f);
}

int main() {
	// read input
	ifstream fin ("checklist.in");
	fin >> H >> G;

	h[0] = g[0] = ii(-1, -1);

	for(int i=0; i<H; i++)
		fin >> h[i+1].f >> h[i+1].s;

	for(int i=0; i<G; i++)
		fin >> g[i+1].f >> g[i+1].s;
	fin.close();

	// dp
	long long dp[1001][1001][2];
	for(int i=0; i<=H; i++)
		for(int j=0; j<=G; j++)
			dp[i][j][0] = dp[i][j][1] = INF;

	dp[1][0][0] = 0;

	for(int i=0; i<=H; i++)
		for(int j=0; j<=G; j++) {
			if(i<H) {
				dp[i+1][j][0] = min(dp[i+1][j][0], 
						min( dp[i][j][0] + calculate(h[i], h[i+1]), dp[i][j][1] + calculate(h[i+1], g[j])));
			}
			if(j<G) {
				dp[i][j+1][1] = min(dp[i][j+1][1], 
						min( dp[i][j][0] + calculate(h[i], g[j+1]), dp[i][j][1] + calculate(g[j], g[j+1])));
			}
		}

	// print output
	ofstream fout ("checklist.out");
	fout << dp[H][G][0] << endl;
	fout.close();

	return 0;
}
