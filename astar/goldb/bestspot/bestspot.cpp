#include <iostream>
#define MAX_N 500
#define INF 100000000
using namespace std;

int P, F, C;
int fav[MAX_N+1];
int path[MAX_N+1][MAX_N+1];

int main() {
	cin >> P >> F >> C;

	for(int i=0; i<F; i++) {
		cin >> fav[i];
	}

	for(int i=1; i<=P; i++)
	for(int j=1; j<=P; j++)
		path[i][j] = INF;

	for(int i=0; i<C; i++) {
		int x, y, t;
		cin >> x >> y >> t;
		path[x][y] = path[y][x] = t;
	}

	// floyd warshall
	for(int k=1; k<=P; k++)
		for(int i=1; i<=P; i++) {
			if(!path[i][k]) continue;
			for(int j=1; j<=P; j++) {
				if(!path[k][j]) continue;

				path[i][j] = min(path[i][j], path[i][k]+path[k][j]);
			}
		}

	// find best barn
	int bestTot = 1000000000;
	int bestID = 0;
	for(int i=1; i<=P; i++) {
		int curr=0;
		for(int j=0; j<F; j++)
			if(i!=fav[j])
				curr += path[fav[j]][i];
		if(curr < bestTot) {
			bestTot = curr;
			bestID = i;
		}
	}

	cout << bestID << endl;
}
