/*
ID: taekyuk1
TASK: holstein
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int V, G;
int minV[25], vit[15][25];

bool arr[15];
bool done = false;


void solve(ofstream &fout) {
	int total[25];
	for(int i=0; i<V; i++) total[i] = 0;

	int count = 0;
	for(int i=0; i<G; i++)
		if(arr[i]) {
			count++;
			for(int j=0; j<V; j++)
				total[j] += vit[i][j];
		}
	
	for(int i=0; i<V; i++)
		if(total[i] < minV[i])
			return;
	
	done = true;
	fout << count;
	for(int i=0; i<G; i++)
		if(arr[i])
			fout << " " << i+1;
	fout << endl;
}

void dfs(int i, int j, ofstream &fout) {
	if(done) return;
	if(j==0) {
		solve(fout);
		return;
	}
	for(int a=i; a+j-1<G; a++) {
		arr[a] = true;
		dfs(a+1, j-1, fout);
		arr[a] = false;
	}
}

int main() {
	// read input
	ifstream fin ("holstein.in");
	fin >> V;
	for(int i=0; i<V; i++)
		fin >> minV[i];
	fin >> G;
	for(int i=0; i<G; i++)
		for(int j=0; j<V; j++)
			fin >> vit[i][j];
	fin.close();

	// iterative bfs
	ofstream fout ("holstein.out");
	for(int i=1; i<=G; i++) {
		dfs(0, i, fout);
	}

	fout.close();

	// end
	return 0;
}
