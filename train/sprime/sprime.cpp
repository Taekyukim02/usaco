/*
ID: taekyuk1
TASK: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

ofstream fout ("sprime.out");

bool isPrime(int p) {
	if(p<2) return false;

	for(int i=2; i*i<=p; i++)
		if(p%i == 0)
			return false;

	return true;
}

void solve(int i, int N) {
	if(N==0) {
		fout << i << endl;
		return;
	}

	N--;
	for(int j=1; j<10; j++)
		if(isPrime(10*i+j))
			solve(10*i+j, N);
}

int main()
{
	int N;
	ifstream fin ("sprime.in");
	fin >> N;
	fin.close();

	solve(0, N);
	fout.close();

	return 0;
}
