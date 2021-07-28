#include <iostream>
#include <fstream>
#include <queue>
#define INF 100000000
using namespace std;

int N;
char grid[20][20];
int dp[20][20][20][20][4];		// minimum number to reach (a,b) dir (e) with other coordinate (c,d)
bool visited[20][20][20][20][4];

struct point {
	int a, b, c, d, e, f;
	point(int v, int w, int x, int y, int z, int k) {
		a = v;
		b = w;
		c = x;
		d = y;
		e = z;
		f = k;
	}
};

int solve() {
	queue <point> bfs;
	bfs.insert( point(0,0,0,0,0,0) );
	bfs.insert( point(0,0,0,0,1,0) );
	dp[0][0][0][0][0] = 0;
	dp[0][0][0][0][1] = 0;

	while(!bfs.empty() && !(visited[N-1][N-1][N-1][N-1][0] ||
							visited[N-1][N-1][N-1][N-1][1] ||
							visited[N-1][N-1][N-1][N-1][2] ||
							visited[N-1][N-1][N-1][N-1][3] ) {
		point p = bfs.front();
		bfs.pop();

		if(visited[p.a][p.b][p.c][p.d][p.e])
			continue;
		visited[p.a][p.b][p.c][p.d][p.e] = true;
		dp[p.a][p.b][p.c][p.d][p.e] = p.f;
		
		// extend to neighbors

	}

	return min(
}

int main() {
	// read input
	ifstream fin ("cownav.in");
	fin >> N;

	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			fin >> grid[N-i-1][j];
	fin.close();

	// initialize dp[]
	for(int i=0; i<N; i++)
	for(int j=0; j<N; j++)
	for(int k=0; k<N; k++)
	for(int l=0; l<N; l++)
	for(int m=0; m<4; m++)
	dp[i][j][k][l][m] = INF;

	// solve
	ofstream fout ("cownav.out");
	fout << solve() << endl;
	fout.close();

	return 0;
}
