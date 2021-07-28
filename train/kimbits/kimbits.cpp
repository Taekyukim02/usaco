/*
ID: taekyuk1
TASK: kimbits
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

long long N, L, I;
long long comb[32][32];
long long sumComb[32][32];

int main() {
	ifstream fin ("kimbits.in");
	fin >> N >> L >> I;
	fin.close();

	comb[0][0] = 1;
	for(int i=1; i<N; i++) {
		comb[i][0] = 1;
		for(int j=1; j<=i; j++) {
			comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
		}
	}
	for(int i=0; i<N; i++) {
		sumComb[i][0] = 1;
		for(int j=1; j<=N; j++) {
			sumComb[i][j] = sumComb[i][j-1] + comb[i][j];
		}
	}

	long long d[32];
	for(int i=0; i<N; i++) {
		long long less = sumComb[N-i-1][L];
		cout << N-i-1 << " " << L << " " << less << endl;
		cout << I << endl;
		if(I > less) {
			I -= less;
			L--;
			d[i] = 1;
		}
		else
			d[i] = 0;
	}

	ofstream fout ("kimbits.out");
	for(int i=0; i<N; i++) {
		fout << d[i];
	}
	fout << endl;
	fout.close();
}

