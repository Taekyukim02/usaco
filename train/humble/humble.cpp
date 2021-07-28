/*
ID: taekyuk1
TASK: humble
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <limits.h>
#include <vector>
#include <algorithm>

using namespace std;

long long S[1000000];

int main() {
	ifstream fin ("humble.in");
	int K, N;
	fin >> K >> N;
	int p[100];
	for(int i=0; i<K; i++)
		fin >> p[i];
	fin.close();

	S[0] = 1;
	int sz = 1;
	long long m = ((long long)1<<32);
	for(int i=0; i<K; i++) {
		int ind = 0;
		while(ind < sz && S[ind] <= m) {
			if(S[ind] % p[i]) {
				long long e = p[i];
				while(e*S[ind] <= m) {
					S[sz] = e*S[ind];
					sz++;
					e *= p[i];
				}
			}
			ind++;
		}
		if(i%4 == 3) {
			sort(S, S+sz);
			sz = min(sz, N+1);
			if(sz == N+1 && m > S[N])
				m = S[N];
		}
	}

	sort(S, S+sz);

	ofstream fout ("humble.out");
	fout << S[N] << endl;
	fout.close();

	return 0;
}
