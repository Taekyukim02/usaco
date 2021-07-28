#include <iostream>
#include <fstream>

#define MOD 1000000007ll

using namespace std;

long long N, K, W, L[2000000], H[2000000], P[2000000];
long long AL, BL, CL, DL, AH, BH, CH, DH;

long long mymax(long long a, long long b) {
	if(a > b) return a;
	return b;
}

int main() {
	ifstream fin ("A1.in");
	ofstream fout ("A1.out");

	long long T; fin >> T;
	for(long long t=1; t<=T; t++) {
		// read input
		fin >> N >> K >> W;
		for(long long i=0; i<K; i++)
			fin >> L[i];
		fin >> AL >> BL >> CL >> DL;
		for(long long i=0; i<K; i++)
			fin >> H[i];
		fin >> AH >> BH >> CH >> DH;
		
		// generate L[], H[]
		for(long long i=K; i<N; i++) {
			L[i] = 1 + (AL * L[i-2] + BL * L[i-1] + CL) % DL;
			H[i] = 1 + (AH * H[i-2] + BH * H[i-1] + CH) % DH;
		}

		// Calculate P[]
		P[0] = 2 * (W + H[0]) % MOD;
		for(long long i=1; i<N; i++) {
			// intersecting
			if(L[i-1] + W >= L[i]) {
				long long j = i-1;
				long long maxH = H[i-1];
				while(j >= 0 && L[j] + W >= L[i]) {
					maxH = mymax(maxH, H[j]);
					j--;
				}
				j++;

				// new block is higher
				if(H[i] > maxH) {
					P[i] = P[i-1] + 2 * (L[i] - L[i-1]) + 2 * (H[i] - maxH);
				}
				// new block is lower
				else {
					P[i] = P[i-1] + 2 * (L[i] - L[i-1]);
				}
				P[i] = P[i] % MOD;
			}
			// not intersecting
			else {
				P[i] = P[i-1] + 2 * (W + H[i]) % MOD;
				P[i] = P[i] % MOD;
			}
		}

		// Print answer
		long long ans = 1;
		for(long long i=0; i<N; i++) {
			ans = (ans * P[i]) % MOD;
		}
		fout << "Case #" << t << ": " << ans << endl;
	}
}

/*
		// Create and sort check[]
		for(int i=0; i<N; i++) {
			check[2*i    ] = iii(ii(L[i]    , 0), i);	// start
			check[2*i + 1] = iii(ii(L[i] + W, 1), i);	// end
		}
		sort(check, check+2N);

		// Solve for perimeters P[]
		for(long long c=0; c<2N; c++) {
			iii nxt = check[c];
			long long i = nxt.s;
			// starting check
			if(nxt.f.s == 0) {
				Q.emplace(H[i], i);
			}

			// ending check
			if(nxt.f.s == 1) {
				while(Q.top().s <= i) 
					Q.pop();
			}
		}
		*/
