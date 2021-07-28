/*
ID: taekyuk1
TASK: maze1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

typedef pair<int,int> ii;
typedef pair<ii, int> pii;

int W, H;
string grid[202];
int main() {
	ifstream fin ("maze1.in");
	fin >> W >> H;
	string in;
	getline(fin, in);
	for(int i=0; i<2*H+1; i++) {
		getline(fin, in);
		grid[i] = in;
		for(int i=0; i<200; i++)
			grid[i] += " ";
	}
	fin.close();

	// find p1, p2 (exits)
	ii p1, p2;
	bool f=0;
	for(int i=1; i<2*W; i+=2) {
		if(grid[0][i] != '-') {
			if(!f) {
				p1 = ii(1,i);
				f = 1;
			}
			else p2 = ii(1,i);
		}
	}
	for(int i=1; i<2*W; i+=2) {
		if(grid[2*H][i] != '-') {
			if(!f) {
				p1 = ii(2*H-1,i);
				f = 1;
			}
			else if(p1.first != 2*H-1 || p1.second != i)
				p2 = ii(2*H-1,i);
		}
	}
	for(int i=1; i<2*H; i+=2) {
		if(grid[i][0] != '|') {
			if(!f) {
				p1 = ii(i,1);
				f = 1;
			}
			else if(p1.first != i || p1.second != 1)
				p2 = ii(i,1);
		}
	}
	for(int i=1; i<2*H; i+=2) {
		if(grid[i][2*W] != '|') {
			if(!f) {
				p1 = ii(i,2*W-1);
				f = 1;
			}
			else if(p1.first != i || p1.second != 2*W-1)
				p2 = ii(i,2*W-1);
		}
	}
/*
	for(int i=0; i<2*H+1; i++)
		cout << grid[i] << endl;
	cout << p1.first << " " << p1.second << endl;
	cout << p2.first << " " << p2.second << endl;

	return 0;
	*/
	// bfs
	int m = 0;
	bool visited[202][202];
	for(int i=0; i<202; i++)
		for(int j=0; j<202; j++)
			visited[i][j] = false;
	queue <pii> bfs;
	bfs.push(pii(p1,1));
	if(p2.first != 0 || p2.second != 0)
		bfs.push(pii(p2,1));
	
	while(!bfs.empty()) {
		pii x = bfs.front();
		bfs.pop();

		if(x.first.first < 0 || x.first.first > 2*H
			|| x.first.second < 0 || x.first.second > 2*W)
			continue;
		if(visited[x.first.first][x.first.second])
			continue;
		visited[x.first.first][x.first.second] = true;

		m = x.second;
		
		if(grid[x.first.first+1][x.first.second] != '-')
			bfs.push(pii(ii(x.first.first+2,x.first.second), x.second+1));
		if(grid[x.first.first-1][x.first.second] != '-')
			bfs.push(pii(ii(x.first.first-2,x.first.second), x.second+1));
		if(grid[x.first.first][x.first.second+1] != '|')
			bfs.push(pii(ii(x.first.first,x.first.second+2), x.second+1));
		if(grid[x.first.first][x.first.second-1] != '|')
			bfs.push(pii(ii(x.first.first,x.first.second-2), x.second+1));
	}

	// print answer
	ofstream fout ("maze1.out");
	fout << m << endl;
	fout.close();
}
