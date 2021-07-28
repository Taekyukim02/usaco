#include <iostream>
#include <fstream>
#include <algorithm>
#include <climits>

using namespace std;

long long T, N, M, K, S, Ap, Bp, Cp, Aq, Bq, Cq, Dp, Dq;
long long P[1000005], Q[1000005];

long long myabs(long long a) {
	if(a >= 0) return a;
	return -a;
}
long long mymin(long long a, long long b) {
	if(a < b) return a;
	return b;
}

int main() {
	ifstream fin ("B.in");
	ofstream fout ("B.out");

	fin >> T;
	for(long long t=1; t<=T; t++) {
		// read input
		fin >> N >> M >> K >> S;
		for(long long i=0; i<K; i++)
			fin >> P[i];
		fin >> Ap >> Bp >> Cp >> Dp;
		for(long long i=0; i<K; i++)
			fin >> Q[i];
		fin >> Aq >> Bq >> Cq >> Dq;

		// generate P_i, Q_i
		for(long long i=K; i<N; i++)
			P[i] = 1 + (Ap * P[i-2] + Bp * P[i-1] + Cp) % Dp;
		for(long long i=K; i<M; i++)
			Q[i] = 1 + (Aq * Q[i-2] + Bq * Q[i-1] + Cq) % Dq;

		// sort P[], Q[] in increasing order
		sort(P, P+N);
		sort(Q, Q+M);
/*
		for(int i=0; i<N; i++)
			cout << P[i] << " \n"[i==N-1];
		for(int i=0; i<M; i++)
			cout << Q[i] << " \n"[i==M-1];
			*/

		// binary search on answer
		long long L = 0;
		long long R = LLONG_MAX;

		while(L < R) {
			long long mid = (L+R)/2;
			
			long long j=0;	// index of first unused log pile
			for(long long i=0; i<N; i++) {
				long long j1 = j;
				long long time = mymin(myabs(P[i]-Q[j1]), myabs(P[i]-Q[j])) 
									+ (Q[j] - Q[j1]) + S * (j - j1 + 1);
				while(j < M && time <= mid) {
					j++;
					time = mymin(myabs(P[i]-Q[j1]), myabs(P[i]-Q[j])) 
										+ (Q[j] - Q[j1]) + S * (j - j1 + 1);
				}
				if(j == M) break;
			}

			if(j == M)
				R = mid;
			else
				L = mid+1;
		}

		// print answer
		fout << "Case #" << t << ": " << L << endl;
	}
}
