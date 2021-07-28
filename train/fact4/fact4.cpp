/*
ID: taekyuk1
TASK: fact4
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int d = 1;
int cnt = 0;

int p(int n, int d) {
	if(n<=1 || n%d) return 0;
	return 1+p(n/d, d);
}

void f(int n) {
	if(n==1) return;
	f(n-1);
	int p2 = p(n,2);
	int p5 = p(n,5);
	cnt += p2 - p5;
	for(int i=0; i<p2; i++) n/=2;
	for(int i=0; i<p5; i++) n/=5;
	d*=n;
	d%=10;
}

int main() {
	ifstream fin("fact4.in");
	int N;
	fin >> N;
	fin.close();

	f(N);
	for(int i=0; i<cnt; i++) {
		d*=2;
		d%=10;
	}
	ofstream fout ("fact4.out");
	fout << d << endl;
	fout.close();
}
