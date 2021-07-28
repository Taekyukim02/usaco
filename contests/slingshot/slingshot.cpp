#include <iostream>
#include <fstream>

using namespace std;

int abs(int x) {
	if(x>=0) return x;
	return -x;
}

int main() {
	int N, M;
	int x[10000],y[10000], t[10000];
	int a[10000], b[10000];

	// read input
	ifstream fin ("slingshot.in");
	fin >> N >> M;

	for(int i=0; i<N; i++)
		fin >> x[i] >> y[i] >> t[i];
	for(int i=0; i<M; i++)
		fin >> a[i] >> b[i];
	fin.close();

	// for each manure...
	ofstream fout ("slingshot.out");
	for(int i=0; i<M; i++) {
		int best = abs(b[i]-a[i]);
		for(int j=0; j<N; j++) {		// try every slingshot
			best = min(best, abs(a[i]-x[j]) + abs(b[i]-y[j]) + t[j]);
		}
		fout << best << endl;
	}
	fout.close();

	return 0;
}
