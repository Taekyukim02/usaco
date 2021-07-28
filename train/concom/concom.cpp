/*
ID: taekyuk1
TASK: concom
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

typedef pair<int,int> ii;

int N, percent[100][100];
bool own[100][100];
queue <ii> bfs;

void solve() {
	for(int i=0; i<100; i++)
		own[i][i] = true;

	while(!bfs.empty()) {
		ii x = bfs.front();
		bfs.pop();

		if(own[x.first][x.second]) continue;
		own[x.first][x.second] = true;

		for(int i=0; i<100; i++) {
			if(i == x.first) continue;

			percent[x.first][i] += percent[x.second][i];
			if(percent[x.first][i] >= 50 && !own[x.first][i])
				bfs.emplace(x.first, i);

			if(!own[i][x.first]) continue;

			percent[i][x.second] += percent[x.first][x.second];
			if(percent[i][x.second] >= 50 && !own[i][x.second])
				bfs.emplace(i, x.second);
		}
	}
}

int main() {
	ifstream fin ("concom.in");
	fin >> N;
	for(int a=0; a<N; a++) {
		int i, j, p;
		fin >> i >> j >> p;
		percent[i-1][j-1] = p;
		if(p >= 50)
			bfs.emplace(i-1, j-1);
	}

	solve();
	
	ofstream fout ("concom.out");
	for(int i=0; i<100; i++)
		for(int j=0; j<100; j++)
			if(i!=j && own[i][j])
				fout << i+1 << " " << j+1 << endl;
	fout.close();
	return 0;
}
