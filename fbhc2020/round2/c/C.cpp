#include <iostream>
#include <fstream>
#include <set>
#include <vector>

#define MOD 1000000007LL

using namespace std;

long long T, N, M, E, K, Ax, Bx, Cx, Ay, By, Cy, Ai, Bi, Ci, Aw, Bw, Cw;
long long X[1000010], Y[1000010], I[1000010], W[1000010];
long long curr[1000010], cmax[2000010];

vector< multiset<long long> > circ(2000010);
multiset<long long> dmax;

long long mymax(long long a, long long b) {
	if(a > b) return a;
	return b;
}

int main() {
	ifstream fin ("C.in");
	ofstream fout ("C.out");

	fin >> T;
	for(long long t=1; t<=T; t++) {
		// read input
		fin >> N >> M >> E >> K;
		for(int i=0; i<K; i++)
			fin >> X[i];
		fin >> Ax >> Bx >> Cx;
		for(int i=0; i<K; i++)
			fin >> Y[i];
		fin >> Ay >> By >> Cy;
		for(int i=0; i<K; i++)
			fin >> I[i];
		fin >> Ai >> Bi >> Ci;
		for(int i=0; i<K; i++)
			fin >> W[i];
		fin >> Aw >> Bw >> Cw;

		// generate input
		for(int i=K; i<N; i++) {
			X[i] = (Ax * X[i-2] + Bx * X[i-1] + Cx) % M;
			Y[i] = (Ay * Y[i-2] + By * Y[i-1] + Cy) % M;
		}
		for(int i=K; i<E; i++) {
			I[i] = (Ai * I[i-2] + Bi * I[i-1] + Ci) % (N*M + N);
			W[i] = (Aw * W[i-2] + Bw * W[i-1] + Cw) % 1000000000;
		}

		for(int i=0; i<N; i++) {
			if(X[i] > Y[i]) {
				long long tmp = X[i];
				X[i] = Y[i];
				Y[i] = tmp;
			}
		}
		for(int i=0; i<E; i++)
			cout << I[i] << " ";
		cout << endl;
		for(int i=0; i<E; i++)
			cout << W[i] << " ";
		cout << endl;

		// initialize sets
		for(int i=0; i<=2*N; i++)
			cmax[i] = 0;

		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				if(X[i] <= j && j < Y[i]) {
					circ[2*i].insert(1);
					cmax[2*i] = 1;
				}
				else {
					circ[2*i+1].insert(1);
					cmax[2*i+1] = 1;
				}
			}
			circ[2*N].insert(1);
			cmax[2*N] = 1;
		}

		for(int i=0; i<=N; i++)
			dmax.insert(1);
		
		for(int i=0; i<N*M+N; i++)
			curr[i] = 1;

		// run events and get product
		long long prod = 1;
		long long prev = N;
		long long tot = N*M + N;
		for(long long e=0; e<E; e++) {
			// update
			tot += W[e] - curr[I[e]];

			if(I[e] < N*M) {
				long long a = I[e] / M;
				long long b = I[e] % M;
				
				if(cmax[2*a] <= cmax[2*a+1]) {
					multiset<long long>::iterator hit(dmax.find(cmax[2*a]));
					if (hit!= dmax.end()) dmax.erase(hit);
				} else {
					multiset<long long>::iterator hit(dmax.find(cmax[2*a+1]));
					if (hit!= dmax.end()) dmax.erase(hit);
				}

				if(X[a] <= b && b < Y[a]) {
					multiset<long long>::iterator hit(circ[2*a].find(curr[I[e]]));
					if (hit!= circ[2*a].end()) circ[2*a].erase(hit);

					curr[I[e]] = W[e];
					circ[2*a].insert(W[e]);

					if(cmax[2*a] > cmax[2*a+1])
						prev = (prev - cmax[2*a] + MOD) % MOD;
					else
						prev = (prev - cmax[2*a+1] + MOD) % MOD;

					cmax[2*a] = *(circ[2*a]).rbegin();

					if(cmax[2*a] > cmax[2*a+1]) {
						prev = (prev + cmax[2*a] + MOD) % MOD;
						dmax.insert(cmax[2*a+1]);
					} else {
						prev = (prev + cmax[2*a+1] + MOD) % MOD;
						dmax.insert(cmax[2*a]);
					}
				} else {
					multiset<long long>::iterator hit(circ[2*a + 1].find(curr[I[e]]));
					if (hit!= circ[2*a+1].end()) circ[2*a + 1].erase(hit);

					curr[I[e]] = W[e];
					circ[2*a + 1].insert(W[e]);
					
					if(cmax[2*a] > cmax[2*a+1])
						prev = (prev - cmax[2*a] + MOD) % MOD;
					else
						prev = (prev - cmax[2*a+1] + MOD) % MOD;

					cmax[2*a+1] = *(circ[2*a+1]).rbegin();

					if(cmax[2*a] > cmax[2*a+1]) {
						prev = (prev + cmax[2*a] + MOD) % MOD;
						dmax.insert(cmax[2*a+1]);
					} else {
						prev = (prev + cmax[2*a+1] + MOD) % MOD;
						dmax.insert(cmax[2*a]);
					}
				}
			} else {
				multiset<long long>::iterator hit(circ[2*N].find(curr[I[e]]));
				if (hit!= circ[2*N].end()) circ[2*N].erase(hit);

				curr[I[e]] = W[e];
				circ[2*N].insert(W[e]);

				cmax[2*N] = *(circ[2*N]).rbegin();
			}
			
			long long smax = mymax(*(circ[2*N]).rbegin(), *dmax.rbegin());

			// find product
			prod = (prod * (tot - smax - prev)) % MOD;
			/*
			for(int i=0; i<N*M+N; i++)
				cout << curr[i] << " ";
			cout << "           ";
			for(int i=0; i<=2*N; i++)
				cout << cmax[i] << " ";
				*/
			cout << "           " << tot - smax - prev;
			cout << endl;
		}

		// output product
		fout << "Case #" << t << ": " << prod << endl;
	}
}
