#include <iostream>
#include <fstream>

#define MAX_N 4000

using namespace std;

int N;
double p[MAX_N+5];
double K[MAX_N+5];
double dp[MAX_N+5][MAX_N+5];

int main() {
	ifstream fin ("cowdate.in");
	fin >> N;
	for(int i=0; i<N; i++) {
		fin >> p[i];
		p[i] /= 1000000;
	}

	K[0] = 1;
	for(int i=0; i<N; i++)
		K[i+1] = K[i] * (1-p[i]);
	
	for(int i=0; i<=N; i++)
		cout << K[i] << endl;

	double best = 0;
	for(int i=0; i<N; i++) {
		dp[i][i] = p[i];
		best = max(best, dp[i][i]);
	}

	for(int j=1; j<N; j++) {
		for(int i=0; i<j; i++) {
			dp[j][i] = dp[j-1][i]*(1-p[j]) + p[j]*K[j]/K[i];
			best = max(best, dp[j][i]);
		}
	}

/*
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++)
			cout << dp[i][j] << "     ";
		cout << endl; 
	}
	*/
	
	ofstream fout ("cowdate.out");
	fout << (int) (best*1000000) << endl;
	fout.close();
}
