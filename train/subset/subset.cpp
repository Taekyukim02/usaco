/*
ID: taekyuk1
TASK: subset
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int N;
long long ans[1600];

void update(int i) {
	for(int a=1599; a>=i; a--)
		ans[a] += ans[a-i];
}

int main() {
	// read input
	ifstream fin ("subset.in");
	fin >> N;
	fin.close();

	ans[0] = 1;
	for(int i=1; i<=N; i++)
		update(i);
	
	// print output
	ofstream fout("subset.out");
	if(N*(N+1)/2 % 2)
		fout << 0 << endl;
	else
		fout << ans[N*(N+1)/4]/2 << endl;
	fout.close();

	return 0;
}
