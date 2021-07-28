/*
ID: taekyuk1
TASK: spin
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int speed[5];
vector <int> s[5];
vector <int> e[5];

int main() {
	ifstream fin ("spin.in");
	for(int i=0; i<5; i++) {
		fin >> speed[i];
		int a;
		fin >> a;
		for(int j=0; j<a; j++) {
			int x, y;
			fin >> x >> y;
			s[i].push_back(x);
			e[i].push_back(y);
		}
	}
	fin.close();

	int i;
	for(i=0; i<360; i++) {
		int cnt[360];
		for(int j=0; j<360; j++) cnt[j] = 0;
		for(int j=0; j<5; j++) {
			for(int k=0; k<s[j].size(); k++) {
				for(int d=0; d<=e[j][k]; d++)
					cnt[(i*speed[j]+s[j][k]+d)%360]++;
			}
		}
		
		int m = 0;
		for(int j=0; j<360; j++)
			m = max(m, cnt[j]);

		if(m==5) {
			break;
		}
	}

	ofstream fout ("spin.out");
	if(i<360)
		fout << i << endl;
	else
		fout << "none" << endl;
	fout.close();
}
