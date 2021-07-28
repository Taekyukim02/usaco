#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

int myabs(int a) {
	if(a < 0) return -a;
	return a;
}

int X[105];
int U[1005];
int V[1005];
bool bag[105];
bool seen[105];
int tme[105];
vector <int> G[105];

priority_queue <ii> Q;

int main() {
	int T; cin >> T;
	for(int t=1; t<=T; t++) {
		int C, D;
		cin >> C >> D;	
		for(int i=0; i<105; i++) {
			G[i].clear();
			bag[i] = 0;
			seen[i] = 0;
			tme[i] = 987654321;
		}

		for(int i=2; i<=C; i++)
			cin >> X[i];
		for(int i=0; i<D; i++) {
			cin >> U[i] >> V[i];
			G[U[i]].push_back(V[i]);
			G[V[i]].push_back(U[i]);
		}

		int cnt = 1;
		int curr = 1;
		bag[1] = 1;
		seen[1] = 1;
		for(int i=1; i < 105; i++) {
			tme[i] = 987654321;
		}
		tme[1] = 1;
		for(int x : G[1]) {
			seen[x] = true;
			Q.emplace(X[x], x);
		}
		while(cnt < C) {
			int smallX = Q.top().first;
			while(!Q.empty() && Q.top().first == smallX) {
				int i = Q.top().second;
				Q.pop();
					
				tme[i] = curr + 1;
				bag[i] = true;
				cnt++;

				for(int x : G[i]) {
					if(seen[x] == false) {
						seen[x] = true;
						Q.emplace(X[x], x);
					}
				}
			}
			curr++;
		}

		cout << "Case #" << t << ":";
		for(int i=0; i<D; i++) {
			int diff = myabs(tme[U[i]] - tme[V[i]]);
			if(diff == 0) diff = 1;
			cout << " " << diff;
		}
		cout << endl;
	}
}
