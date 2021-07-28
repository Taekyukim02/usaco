/*
ID: taekyuk1
TASK: lamps
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int N, C;
int on[100], off[100];
int numOn = 0;
int numOff = 0;
bool cand[16][100];
int cnt[16];

void button1(int i) {
	cnt[i]++;
	for(int j=0; j<N; j++)
		cand[i][j] = !cand[i][j];
}
void button2(int i) {
	cnt[i]++;
	for(int j=0; j<N; j+=2)
		cand[i][j] = !cand[i][j];
}
void button3(int i) {
	cnt[i]++;
	for(int j=1; j<N; j+=2)
		cand[i][j] = !cand[i][j];
}
void button4(int i) {
	cnt[i]++;
	for(int j=0; j<N; j+=3)
		cand[i][j] = !cand[i][j];
}

int main() {
	// read input
	ifstream fin ("lamps.in");
	fin >> N >> C;
	do {
		fin >> on[numOn];
		on[numOn]--;
		numOn++;
	} while (on[numOn-1] != -2);
	do {
		fin >> off[numOff];
		off[numOff]--;
		numOff++;
	} while (off[numOff-1] != -2);
	fin.close();

	// create all possible candidates
	for(int i=0; i<100; i++)
		for(int j=0; j<16; j++)
			cand[j][i] = true;
	for(int i=0; i<16; i++)
		cnt[i] = 0;
		
	for(int i=0; i<8; i++) button1(i); 
	for(int i=0; i<4; i++) button2(i);
	for(int i=8; i<12; i++) button2(i);
	for(int i=0; i<2; i++) button3(i); 
	for(int i=4; i<6; i++) button3(i); 
	for(int i=8; i<10; i++) button3(i); 
	for(int i=12; i<14; i++) button3(i); 
	for(int i=0; i<16; i+=2) button4(i); 
/*
	for(int i=0; i<16; i++) {
		for(int j=0; j<N; j++)
			cout << cand[i][j];
		cout << "    " << cnt[i] << endl;
	}
*/
	// remove impossible ones
	bool poss[16];
	for(int i=0; i<16; i++)	poss[i] = true;

	for(int i=0; i<16; i++) {
		if(cnt[i] > C || (cnt[i] - C) % 2) {
			poss[i] = false;
			continue;
		}
		for(int j=0; j<numOn-1; j++)
			if(cand[i][ on[j] ] != true) {
				poss[i] = false;
				break;
			}
		for(int j=0; j<numOff-1; j++)
			if(cand[i][ off[j] ] != false) {
				poss[i] = false;
				break;
			}
	}


	// turn candidate arrays into strings
	string c[16];
	map <string, int> output;
	for(int i=0; i<16; i++) c[i] = "";

	for(int i=0; i<16; i++) {
		if(poss[i]) {
			for(int j=0; j<N; j++)
				c[i] += to_string(cand[i][j]);
			output[c[i]] = 1;
		}
	}

	// print output
	ofstream fout ("lamps.out");
	if(output.size() == 0)
		fout << "IMPOSSIBLE" << endl;
	else
		for(auto it = output.begin(); it != output.end(); ++it)
			fout << it->first << endl;

	fout.close();
	return 0;
}
