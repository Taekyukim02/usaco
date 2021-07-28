/*
ID: taekyuk1
TASK: castle
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <queue>
#define MAX_N 50
#define f first
#define s second

using namespace std;

typedef pair<int,int> ii;

int M, N;
int grid[MAX_N][MAX_N];
int component[MAX_N][MAX_N];
int numInComponent[MAX_N * MAX_N];
int numComponent;

void floodfill() {
	numComponent = 0;
	bool visited[MAX_N][MAX_N];
	for(int i=0; i<MAX_N; i++)
		for(int j=0; j<MAX_N; j++)
			visited[i][j] = false;

	// for every module
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++) {
			if(!visited[i][j]) {
				queue <ii> bfs; 
				bfs.push(make_pair(i,j));
				while(!bfs.empty()) {
					ii x = bfs.front();
					bfs.pop();
					
					if(visited[x.f][x.s]) continue;

					visited[x.f][x.s] = true;
					component[x.f][x.s] = numComponent;
					numInComponent[numComponent]++;

					if(!(grid[x.f][x.s] & 1)) bfs.push(make_pair(x.f, x.s-1));
					if(!(grid[x.f][x.s] & 2)) bfs.push(make_pair(x.f-1, x.s));
					if(!(grid[x.f][x.s] & 4)) bfs.push(make_pair(x.f, x.s+1));
					if(!(grid[x.f][x.s] & 8)) bfs.push(make_pair(x.f+1, x.s));
				}
				numComponent++;
			}
		}
}

ii destM;
char destD;

int destroyWall() {
	int maxRoom = 0;
	for(int j=0; j<M; j++)
		for(int i=N-1; i>=0; i--) {
			// try north wall
			if(i-1>=0 && component[i][j] != component[i-1][j] 
					&& numInComponent[component[i][j]] + numInComponent[component[i-1][j]] > maxRoom) {
				maxRoom = numInComponent[component[i][j]] + numInComponent[component[i-1][j]];
				destD = 'N';
				destM = make_pair(i,j);
			}

			// try east wall
			if(j+1<M && component[i][j] != component[i][j+1] 
					&& numInComponent[component[i][j]] + numInComponent[component[i][j+1]] > maxRoom) {
				maxRoom = numInComponent[component[i][j]] + numInComponent[component[i][j+1]];
				destD = 'E';
				destM = make_pair(i,j);
			}
		}

	return maxRoom;
}

int main() {
	// read input
	ifstream fin ("castle.in");
	fin >> M >> N;

	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			fin >> grid[i][j];

	// find components
	floodfill();

	// print number of rooms
	ofstream fout ("castle.out");
	fout << numComponent << endl;

	// find biggest room
	int maxRoom = 0;
	for(int i=0; i<numComponent; i++)
		maxRoom = max(maxRoom, numInComponent[i]);
	fout << maxRoom << endl;

	// destroy walls!
	fout << destroyWall() << endl;
	fout << destM.f+1 << " " << destM.s+1 << " " << destD << endl;

	fout.close();
	return 0;
}

