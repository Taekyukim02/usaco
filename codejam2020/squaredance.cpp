#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> ii;

ii nxt[4][100005];
bool removed[100005];
int s[100005];
queue <int> Q;

long long solve() {
	for(int i=0; i<100005; i++)
		removed[i] = 0;

	int R, C;
	long long ret = 0;
	cin >> R >> C;
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			cin >> s[C*i + j];

	for(int j=0; j<C; j++) {
		nxt[0][C*0 + j] = ii(-1, -1);
		for(int i=1; i<R; i++)
			nxt[0][C*i + j] = ii(i-1, j);
	}
	for(int j=0; j<C; j++) {
		nxt[2][C*(R-1) + j] = ii(-1, -1);
		for(int i=0; i<R-1; i++)
			nxt[2][C*i + j] = ii(i+1, j);
	}
	for(int i=0; i<R; i++) {
		nxt[3][C*i + 0] = ii(-1, -1);
		for(int j=1; j<C; j++)
			nxt[3][C*i + j] = ii(i, j-1);
	}
	for(int i=0; i<R; i++) {
		nxt[1][C*i + (C-1)] = ii(-1, -1);
		for(int j=0; j<C-1; j++)
			nxt[1][C*i + j] = ii(i, j+1);
	}
	
	// For each round...
	bool cont = 1;
	while(cont) {
		/*
		cout << "Round..." << endl;
		for(int i=0; i<R*C; i++)
			cout << removed[i];
		cout << endl;

		for(int i=0; i<R*C; i++)
			for(int t=0; t<4; t++)
				cout << nxt[t][i].first << " " << nxt[t][i].second  << endl;
			cout << endl;
			*/


		for(int i=0; i<R; i++)
			for(int j=0; j<C; j++)
				if(!removed[C*i + j])
					ret += s[C*i + j];

		cont = 0;
		// try to eliminate cows
		for(int i=0; i<R; i++)
			for(int j=0; j<C; j++) { 
				int hsh = C*i + j;
				if(!removed[hsh]) {
					int num = 0;
					int tot = 0;
					for(int t=0; t<4; t++) {
						int nxthsh = C*nxt[t][hsh].first + nxt[t][hsh].second;
						if(nxthsh >= 0) {
							num++;
							tot += s[nxthsh];
						}
					}
//						cout << "Trying " << i << " " << j << " " << endl;
//						cout << tot << " " << num << " " << s[hsh] << endl;
					if(tot > num * s[hsh]) {
						removed[hsh] = 1;
						Q.push(hsh);
						cont = 1;
					}
				}
			}

		// for each eliminated cow, update neighbors
		while(!Q.empty()) {
			int hsh = Q.front();
			Q.pop();
			if(nxt[2][hsh].first >= 0) {
				int nxthsh = nxt[2][hsh].first*C + nxt[2][hsh].second;
				nxt[0][nxthsh] = nxt[0][hsh];
			}
			if(nxt[3][hsh].first >= 0) {
				int nxthsh = nxt[3][hsh].first*C + nxt[3][hsh].second;
				nxt[1][nxthsh] = nxt[1][hsh];
			}
			if(nxt[0][hsh].first >= 0) {
				int nxthsh = nxt[0][hsh].first*C + nxt[0][hsh].second;
				nxt[2][nxthsh] = nxt[2][hsh];
			}
			if(nxt[1][hsh].first >= 0) {
				int nxthsh = nxt[1][hsh].first*C + nxt[1][hsh].second;
				nxt[3][nxthsh] = nxt[3][hsh];
			}
		}
	}
	return ret;
}

int main() {
	int T; cin >> T;
	for(int t=1; t<=T; t++) {
		cout << "Case #" << t << ": " << solve() << endl;
	}
}
