/*
ID: taekyuk1
TASK: agrinet
LANG: C++
*/
#include <iostream>
#include <fstream>
#define INF 100000000

using namespace std;

int main() {
	int N;
	int grid[100][100];
	ifstream fin ("agrinet.in");
	fin >> N;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			fin >> grid[i][j];
	fin.close();

	int tot = 0;
	bool visited[100];
	int dist[100];
	for(int i=0; i<N; i++) {
		visited[i] = 0;
		dist[i] = INF;
	}
	dist[0] = 0;
	for(int i=0; i<N; i++) {
		int bN=-1;
		for(int j=0; j<N; j++)
			if(!visited[j] && (bN==-1 || dist[bN] > dist[j]))
				bN = j;

		if(bN == -1) {
			cout << "SOMETHING WRONG" << endl;
			return 0;
		}

		visited[bN] = true;
		tot += dist[bN];
		for(int j=0; j<N; j++) {
			if(!visited[j] && grid[bN][j] < dist[j])
				dist[j] = grid[bN][j];
		}
	}

	ofstream fout ("agrinet.out");
	fout << tot << endl;
	fout.close();
	return 0;
}
