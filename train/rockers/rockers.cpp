/*
ID: taekyuk1
TASK: rockers 
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int N, T, M;
int songs[20];
bool picked[20];

// returns true if picked list is valid
bool valid_pick() {
	int d=0, t=0;
	for(int i=0; i<N; i++) {
		if(picked[i]) {
			t += songs[i];
			if(t > T) {
				t = songs[i];
				d++;
			}
			if(t > T)
				return false;
		}
	}
//	if(picked[0] && picked[1] && picked[2] && picked[3])
//		cout << d << " " << M << endl;
	if(d < M)
		return true;
	else
		return false;
}

int best = 0;
void dfs(int i, int num) {
//	for(int i=0; i<N; i++)
//		cout << picked[i] << " \n"[i==N-1];

	if(i == N) {
		if(valid_pick()) {
			best = max(best, num);
		}
		return;
	}

	dfs(i+1, num);

	picked[i] = true;
	dfs(i+1, num+1);
	picked[i] = false;
}

int main() {
	ifstream fin ("rockers.in");
	fin >> N >> T >> M;
	for(int i=0; i<N; i++)
		fin >> songs[i];
	fin.close();

	dfs(0, 0);

	ofstream fout ("rockers.out");
	fout << best << endl;
	fout.close();
}
