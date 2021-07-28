/*
ID: taekyuk1
TASK: pprime
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#define MAX_N 10000000

using namespace std;

int a, b;
bool isComposite[MAX_N];

void makePrimes() {
	for(int i=2; i*i <=b && i*i < MAX_N; i++) {
		if(isComposite[i]) continue;

		for(int j=2; i*j<=b && i*j < MAX_N; j++)
			isComposite[i*j] = true;
	}
}

bool isPalin(int i) {
	string str = to_string(i);
	for(int j=0; j*2<=str.length(); j++)
		if(str[j] != str[str.length()-1-j])
			return false;
	return true;
}

int main()
{
	ifstream fin("pprime.in");
	fin >> a >> b;
	fin.close();

	makePrimes();

	ofstream fout("pprime.out");
	for(int i=a; i<=b && i<MAX_N; i++)
		if(!isComposite[i] && isPalin(i))
			fout << i << endl;
	fout.close();

	return 0;
}
