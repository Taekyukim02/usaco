#include <iostream>
#include <fstream>
#define MOD 1000000007ll

using namespace std;

int N, K, c[100000];

long long expo(long long b, long long e) {
	if(e == 0) return 1;
	if(e == 1) return b;
	if(e%2) return b*expo(b*b%MOD, e/2)%MOD;
	return expo(b*b%MOD, e/2)%MOD;
}

int main() {
	ifstream fin ("tracking2.in");
	fin >> N >> K;
	for(int i=0; i<N; i++)
		fin >> c[i];
	fin.close();

	int k, streak;
	for(int i=0; i<N+1-K; i++) {
		
	}
}
