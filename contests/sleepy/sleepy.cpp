#include <iostream>
#include <fstream>

#define MAX_N 105

using namespace std;

int N, p[MAX_N];

int solve() {
	for(int i=N-2; i>=0; i--)
		for(int j=i+1; j<N; j++)
			if(p[i] > p[j])
				return i+1;
	return 0;
}

int main() {
	ifstream fin ("sleepy.in");
	fin >> N;
	for(int i=0; i<N; i++)
		fin >> p[i];
	fin.close();

	ofstream fout ("sleepy.out");
	fout << solve() << endl;
	fout.close();
}
