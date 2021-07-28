/*
ID: taekyuk1
TASK: frac1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

struct frac{
	int num;
	int den;
	frac(int a, int b) {
		num = a;
		den = b;
	}
};

int gcd(int n,int m){return m==0?n:gcd(m,n%m);}

vector <frac> f;

// make fractions with denominators from 1 to N
void makeFrac(int N) {
	for(int d=2; d<=N; d++) 
		for(int n=1; n<d; n++)
			if( gcd(n,d) == 1)
				f.push_back( frac(n,d) );

	// account for 0/N and 1/1
	f.push_back( frac(0,1) );
	f.push_back( frac(1,1) );
}


bool comp(const frac f1, const frac f2) {
	return f1.num*f2.den < f2.num*f1.den;
}

int main() {
	int N;

	ifstream fin ("frac1.in");
	fin >> N;
	fin.close();

	makeFrac(N);
	sort(f.begin(), f.end(), comp);

	ofstream fout ("frac1.out");
	for(auto it=f.begin(); it!=f.end(); ++it) 
		fout << it->num << "/" << it->den << endl;
	fout.close();

	return 0;
}
