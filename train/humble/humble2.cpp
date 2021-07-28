/*
ID: taekyuk1
TASK: humble
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <limits.h>

using namespace std;

int main() {
	ifstream fin ("humble.in");
	int K, N;
	fin >> K >> N;
	long long p[100];
	for(int i=0; i<K; i++)
		fin >> p[i];
	fin.close();

	int pindex[100];
	for(int i=0; i<K; i++) pindex[i] = 0;

	long long h[100001];
	h[0] = 1;
	for(int i=1; i<=N; i++) {
		int mindex = i;
		long long n = LONG_MAX;
		for(int j=0; j<K; j++) {
			int id = pindex[j];
			while(id < i && p[j] * h[id] <= h[i-1])
				id++;
			if(id > pindex[j]) {
				pindex[j] = id;
			}
			if(n > p[j]*h[id]) {
				n = p[j] * h[id];
			}
		}
		h[i] = n;
	}
	
	ofstream fout ("humble.out");
	fout << h[N] << endl;
	fout.close();
}
