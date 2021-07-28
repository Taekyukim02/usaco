/*
ID: taekyuk1
TASK: fracdec
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int numDigits(int n) {
	int ret=0;;
	if(n==0)
		return 1;
	while(n>0) {
		n/=10;
		ret++;
	}
	return ret;
}

int main() {
	int N, D;
	ifstream fin ("fracdec.in");
	fin >> N >> D;
	fin.close();

	int front = N/D;
	N %= D;
	if(N==0) {
		ofstream fout ("fracdec.out");
		fout << front << ".0" << endl;
		fout.close();
		return 0;
	}
	int oriN = N;

	char deci[100000];
	int ind = 0;
	int visited[100000];
	for(int i=0; i<100000; i++)
		visited[i] = 0;

	while(!visited[N] && N!=0) {
		deci[ind] = (char) ((10*N)/D + '0');
		visited[N] = ind;
		if(N == oriN)
			visited[N] = 1;
		
		ind++;
		N = (10*N)%D;
	}
	
	visited[oriN] = 0;

	if(N == 0) {
		ofstream fout("fracdec.out");
		int i = numDigits(front)+1;
		fout << front << ".";
		for(int a=0; a<ind; a++) {
			fout << deci[a];
			i++;
			if(i%76 == 0) fout << endl;
		}
		if(i%76 != 0) fout << endl;
		fout.close();
	} else {
		ofstream fout("fracdec.out");
		int i = numDigits(front)+1;
		fout << front << ".";
		for(int a=0; a<ind; a++) {
			if(a == visited[N]) {
				fout << "(";
				i++;
				if(i%76 == 0) fout << endl;
			}
			fout << deci[a];
			i++;
			if(i%76 == 0) fout << endl;
		}
		fout << ")" << endl;
		fout.close();
	}

	return 0;
}
