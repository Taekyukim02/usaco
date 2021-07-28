#include <iostream>
#include <fstream>

using namespace std;

long long T, N;
long double P, E[8010][8010];
long long binom[8010];

int main() {
	ifstream fin ("B.in");
	ofstream fout ("B.out");
	
	// make binom[]

	for(int i=0; i<8010; i++)
		binom[i] = i*(i-1) / 2;

	fin >> T;
	for(int t=1; t<=T; t++) {
		// read input
		fin >> N >> P;

		// algorithm
		E[1][1] = 0;
		E[1][2] = 1;
		E[2][2] = 1;
		E[0][1] = E[2][1] = E[0][2] = E[3][2] = 0;

		for(int n=3; n<=N; n++) {
			for(int i=1; i<=n; i++) {
				E[i][n] = binom[i-1] * E[i-1][n-1] + (i-1)*(n-i)*P * E[i-1][n-1]
							+ (i-1)*(n-i)*(1-P) * E[i][n-1] 
							+ binom[n-i] * E[i][n-1]
							+ (i-1)*P * E[i-1][n-1] + (n-i)*(1-P) * E[i][n-1];
				E[i][n] /= binom[n];
				E[i][n] += 1;
			}
		}

		// output
		fout << "Case #" << t << ":" << endl;
		for(int i=1; i<=N; i++) {
			fout.precision(17);
			fout << fixed << E[i][N] << endl;
		}
	}
}
