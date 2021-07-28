/*
ID: taekyuk1
TASK: camelot
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <queue>
#define f first
#define s second

using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> pii;

int R, C, N=0;
ii king, knight[26*30];

int main() {
	// read input
	ifstream fin ("camelot.in");
	char temp;
	fin >> R >> C >> temp >> king.s;
	king.f = (int) (temp - 'A');
	king.s--;
	while(fin >> temp >> knight[N].s) {
		knight[N].f = (int) (temp - 'A');
		knight[N].s--;
		N++;
	}
	fin.close();

	// get shortest distance matrix
	int sDist[26][30][26][30];
	for(int i=0; i<26; i++)
	for(int j=0; j<30; j++)
	for(int k=0; k<26; k++)
	for(int l=0; l<30; l++)
		sDist[i][j][k][l] = 987654321;

	for(int a=0; a<C; a++)
	for(int b=0; b<R; b++) {
		queue<pii> bfs;
		bfs.emplace(ii(a,b), 0);
		while(!bfs.empty()) {
			pii x = bfs.front();
			bfs.pop();
			
			if(x.f.f<0 || x.f.f>=C || x.f.s<0 || x.f.s>=R || sDist[a][b][x.f.f][x.f.s] != 987654321)
				continue;

			sDist[a][b][x.f.f][x.f.s] = x.s;

			bfs.emplace(ii(x.f.f+1, x.f.s+2), x.s+1);
			bfs.emplace(ii(x.f.f-1, x.f.s+2), x.s+1);
			bfs.emplace(ii(x.f.f+1, x.f.s-2), x.s+1);
			bfs.emplace(ii(x.f.f-1, x.f.s-2), x.s+1);
			bfs.emplace(ii(x.f.f+2, x.f.s+1), x.s+1);
			bfs.emplace(ii(x.f.f-2, x.f.s+1), x.s+1);
			bfs.emplace(ii(x.f.f+2, x.f.s-1), x.s+1);
			bfs.emplace(ii(x.f.f-2, x.f.s-1), x.s+1);
		}
	}

/*
	for(int i=0; i<26; i++)
	for(int j=0; j<30; j++)
		cout << sDist[3][5][i][j] << " \n"[j==29];
		*/

	// try all possibilities
	int ans = 987654321;
	for(int a=0; a<C; a++)
		for(int b=0; b<R; b++) {
			int sum=0;
			bool good=true;
			int bad = -1;
			for(int j=0; j<N; j++) {
				if(sDist[a][b][knight[j].f][knight[j].s] == 987654321) {
					if(bad != -1)
						good=false;
					bad = j;
				}
				sum += sDist[a][b][knight[j].f][knight[j].s];
			}

			if(good==false) break;
			if(sum >= ans) continue;

			for(int i=0; i<N; i++) {
				if(bad != -1)
					i = bad;

				int curr = sum - sDist[a][b][knight[i].f][knight[i].s];
			
				for(int c=0; c<C; c++)
					for(int d=0; d<R; d++) { 
						int m = sDist[c][d][knight[i].f][knight[i].s]
								+ sDist[a][b][c][d]
								+ max(abs(king.f-c), abs(king.s-d));

						ans = min(ans, curr+m);
					}

				if(bad != -1)
					break;
			}
		}

	if(N==0)
		ans = 0;

	// print output
	ofstream fout ("camelot.out");
	fout << ans << endl;
	fout.close();

	return 0;
}
