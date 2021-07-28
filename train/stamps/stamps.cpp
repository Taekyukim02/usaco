/*
ID: taekyuk1
TASK: stamps
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

bool p[2000000];
int s[50];

int main() {
	int N, K;
	int maxS = -1;
	ifstream fin ("stamps.in");
	fin >> K >> N;
	for(int i=0; i<N; i++) {
		fin >> s[i];
		maxS = max(maxS, s[i]);
	}
	fin.close();
	
	p[0] = true;
	for(int i=0; i<K; i++) {
		for(int j=maxS*(i+1); j>=0; j--) {
			if(p[j]) continue;
			for(int k=0; k<N; k++)
				if(j-s[k]>=0 && p[j-s[k]]) {
					p[j] = true;
					break;
				}
		}
	}
	
	long long cnt = 0;
	for(int i=1; i<=maxS*K; i++)
		if(p[i]) cnt++;
		else	 break;

	ofstream fout ("stamps.out");
	fout << cnt << endl;
	fout.close();
}
