#include <iostream>
#include <fstream>

#define MAX_N 55
#define MAX_M 1005
#define inf 987654321LL

using namespace std;

long long T, N, M, X[MAX_M], Y[MAX_M], Z[MAX_M];
long long dist[MAX_N][MAX_N]; 

int main() {
	ifstream fin ("p1.txt");
	ofstream fout ("output.txt");

	//cin >> T;
	fin >> T;
	for(int i=1; i<=T; i++) {
		//cin >> N >> M;
		fin >> N >> M;
		for(int j=1; j<=N; j++)
			for(int k=1; k<=N; k++)
				dist[j][k] = inf;

		for(int j=1; j<=N; j++)
			dist[j][j] = 0;

		for(int j=0; j<M; j++) {
			//cin >> X[j] >> Y[j] >> Z[j];
			fin >> X[j] >> Y[j] >> Z[j];
			dist[X[j]][Y[j]] = dist[Y[j]][X[j]] = Z[j];
		}

		// floyd-warshall
		for(int c=1; c<=N; c++) {
			for(int a=1; a<=N; a++) {
				for(int b=1; b<=N; b++) {
					if(dist[a][b] > dist[a][c] + dist[c][b])
						dist[a][b] = dist[a][c] + dist[c][b];
				}
			}
		}

/*
		for(int a=1; a<=N; a++)
		for(int b=1; b<=N; b++)
			cout << dist[a][b] << " \n"[b==N];
			*/
		// check distances
		bool f = true;
		for(int j=0; j<M; j++)
			if(dist[X[j]][Y[j]] != Z[j]) {
				//cout << "fail at " << j << endl;
				f = false;
			}

		if(f == true) {
			fout << "Case #" << i << ": " << M << endl;
			for(int j=0; j<M; j++)
				fout << X[j] << " " << Y[j] << " " << Z[j] << endl;
		}
		else
			fout << "Case #" << i << ": Impossible" << endl;
	}
}
