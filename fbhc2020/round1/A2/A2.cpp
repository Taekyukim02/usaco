#include <iostream>
#include <fstream>

#define MOD 1000000007ll

using namespace std;

long long M, N, K, W[4000000], L[4000000], H[4000000], P[4000000];
long long AL, BL, CL, DL, AH, BH, CH, DH, AW, BW, CW, DW;
long long pos[4000010], rgt[4000010], hgt[4000010], edgehgt[4000010];

long long mymax(long long a, long long b) {
	if(a > b) return a;
	return b;
}

long long posfind(long long p) {
	long long a = 0;
	long long b = M-1;
	while(a < b) {
		long long mid = (a + b)/2;
		if(pos[mid] == p) {
			a = mid;
			break;
		}
		if(pos[mid] < p) {
			a = mid + 1;
		} else {
			b = mid - 1;
		}
	}
	return a;
}

long long d;

long long teleport(long long a, long long depth) {
	if(edgehgt[rgt[a]] == 0)
		return (rgt[a] = rgt[a]);
	d = depth;
	return (rgt[a] = teleport(rgt[a]+1, depth+1));
}

int main() {
	ifstream fin ("A2.in");
	ofstream fout ("A2.out");

	long long T; fin >> T;
	for(long long t=1; t<=T; t++) {
		// read input
		fin >> N >> K;
		for(long long i=0; i<K; i++)
			fin >> L[i];
		fin >> AL >> BL >> CL >> DL;
		for(long long i=0; i<K; i++)
			fin >> W[i];
		fin >> AW >> BW >> CW >> DW;
		for(long long i=0; i<K; i++)
			fin >> H[i];
		fin >> AH >> BH >> CH >> DH;
		
		// generate L[], H[], W[]
		for(long long i=K; i<N; i++) {
			L[i] = 1 + (AL * L[i-2] + BL * L[i-1] + CL) % DL;
			W[i] = 1 + (AW * W[i-2] + BW * W[i-1] + CW) % DW;
			H[i] = 1 + (AH * H[i-2] + BH * H[i-1] + CH) % DH;
		}

		// reset pos, rgt, hgt
		for(int i=0; i<N; i++) {
			pos[2*i] = L[i];
			pos[2*i+1] = L[i] + W[i];
		}
		sort(pos, pos + 2*N);

		M = 1;
		for(int i=1; i<2*N; i++) {
			if(pos[i] != pos[i-1]) {
				pos[M] = pos[i];
				M++;
			}
		}

		for(int i=0; i < M; i++) {
			rgt[i] = i;
			hgt[i] = edgehgt[i] = 0;
		}

		// Calculate P[]
		long long perim = 0;
		/*
		for(int j=0; j<M; j++)
			cout << pos[j] << " ";
		cout << endl;
		*/
		for(long long i=0; i<N; i++) {
			// find left, right pos indices
			long long A = posfind(L[i]);
			long long B = posfind(L[i] + W[i]);

			// go from left to right
			long long inc = 0;
			long long numint = 0;
			long long a;
			bool separate = true;
			for(a = A; a < B; a++) {
				if(edgehgt[a] == 0) {
					inc += pos[a+1] - pos[a];
					edgehgt[a] = H[i];
				}
				// already filled in
				if(hgt[a] > 0) {
					a = teleport(a, 1);
					numint++;
					if(a < B) {
						inc += pos[a+1] - pos[a];
						edgehgt[a] = H[i];
					}
					if(a == B)
						separate = false;
				}
				// not filled in
				else {
					hgt[a] = H[i];
					separate = true;
				}

				rgt[a] = B;
			}
			if(separate && a == B && hgt[B] > 0)
				numint++;
			else
				hgt[B] = H[i];

			// add perim for horizontal parts
			perim = (perim + 2 * inc) % MOD;

			// subtract perim for vertical overlap
			if(numint >= 2)
				perim -= 2 * H[i] * (numint - 1);

			// add perim if disjoint
			if(numint == 0)
				perim = (perim + 2 * H[i]) % MOD;

			// add perimeter
			perim = perim % MOD;
			P[i] = perim;

/*
			for(int j=0; j<M; j++)
				cout << hgt[j] << " ";
			cout << endl;

			cout << inc << " " << numint << " " << perim << endl;
			*/
		}


		// Print answer
		long long ans = 1;
		for(long long i=0; i<N; i++) {
			ans = (ans * P[i]) % MOD;
		}
		fout << "Case #" << t << ": " << ans << endl;
	}
}
