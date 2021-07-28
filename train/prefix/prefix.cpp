/*
ID: taekyuk1
TASK: prefix
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#define MOD 1000000009ll
#define prime 31ll

using namespace std;

map <long long, int> prim;
long long pre[200000];

long long ppowr(long long p, long long e) {
	if(e == 0) return 1;
	if(e == 1) return p;
	if(e%2 == 1) return p*ppowr(p*p%MOD, (e-1)/2) % MOD;
	return ppowr(p*p%MOD, e/2) % MOD;
}

long long hsh(string str) {
	long long ret = 0;
	for(int i=0; i<str.length(); i++)
		ret = (ret + (ppowr(prime, i) * str[i]) % MOD) % MOD ;
	return ret;
}

void prehsh(string str) {
	pre[0] = str[0];
	for(int i=1; i<str.length(); i++)
		pre[i] = (pre[i-1] + (ppowr(prime, i) * str[i]) % MOD) % MOD;
}

int main() {
	string input;
	ifstream fin ("prefix.in");
	do {
		fin >> input;
		if(input != ".") {
			prim[hsh(input)] = 1;
//			cout << input << " is " << hsh(input) << endl;
		}
	} while (input != ".");

	string S;
	while(fin >> input)
		S += input;
	fin.close();

	prehsh(S);
/*	for(int i=0; i<7; i++)
		cout << "prehsh" << pre[i] << endl;
*/
	// dp
	bool reachable[200000];
	int ans = -1;
	for(int i=0; i<200000; i++) reachable[i] = false;

	for(int i=0; i<S.length() && ans >= i-11; i++) {
		for(int j=i-1; j>=-1 && i-j<=10; j--) {
			if(j>=0 && !reachable[j]) continue;

			long long a;
			if(j==-1) a = pre[i];
			else a = ((pre[i]-pre[j]+MOD)%MOD * ppowr(prime, MOD-1-j-1))%MOD;

//			cout << j << " to " << i << " is " << a << endl;

			if(prim.find(a) != prim.end()) {
				reachable[i] = true;
				ans = i;
				break;
			}
		}
	}

/*	for(int i=0; i<13; i++)
		cout << i << " " << reachable[i] << endl;
*/
	// output answer
	ofstream fout ("prefix.out");
	fout << ans+1 << endl;
	fout.close();
}
