/*
ID: taekyuk1
TASK: comehome
LANG: C++
*/
#include <iostream>
#include <fstream>
#define INF 1000000000

using namespace std;

int P;
int dist[52][52];

int mp(char x) {
	if('A' <= x && x <= 'Z')
		return x-'A';
	return x-'a'+26;
}

int main() {
	for(int i=0; i<52; i++)
		for(int j=0; j<52; j++)
			dist[i][j] = INF;

	ifstream fin ("comehome.in");
	fin >> P;
	for(int i=0; i<P; i++) {
		char a, b;
		int c;
		fin >> a >> b >> c;
		dist[mp(a)][mp(b)] = min(dist[mp(a)][mp(b)], c);
		dist[mp(b)][mp(a)] = min(dist[mp(b)][mp(a)], c);
	}
	fin.close();
	
	int bestDist[52];
	bool visited[52];
	for(int i=0; i<52; i++) {
		bestDist[i] = INF;
		visited[i] = false;
	}
	bestDist[mp('Z')] = 0;
	for(int i=0; i<52; i++) {
		int m = -1;
		for(int j=0; j<52; j++) 
			if(!visited[j] && (m==-1 || bestDist[m] > bestDist[j]))
				m = j;
		
		if(m == -1 || bestDist[m] >= INF)
			break;

		visited[m] = true;
		for(int j=0; j<52; j++)
			if(!visited[j] && bestDist[j] > bestDist[m] + dist[m][j])
				bestDist[j] = bestDist[m] + dist[m][j];
	}

	ofstream fout ("comehome.out");
	char best = 'A';
	for(char i='A'; i<'Z'; i++) {
		if(bestDist[mp(best)] > bestDist[mp(i)])
			best = i;
	}
	fout << best << " " << bestDist[mp(best)] << endl;
	fout.close();

	return 0;
}
