#include <iostream>
#include <cmath>

using namespace std;

bool used[16];
int order[16];
int bestK = 0;
int N, M;
int a[16][10000];
int K;

void dfs(int ind, int currK) {
	if(ind == N) {
		int d = 1000000000;
		for(int j=0; j<M-1; j++)
			d = min(d, abs(a[order[N-1]][j]-a[order[0]][j+1]));
		currK = min(currK, d);
		/*
		for(int i=0; i<N; i++) {
			cout << order[i] << endl;
			for(int j=0; j<M; j++)
				cout << a[order[i]][j] << " \n"[j==M-1];
		}
		cout << currK << " " << bestK << endl;
		*/
		bestK = max(bestK, currK);
		return;
	}
	if(currK <= bestK)
		return;

	for(int i=N-1; i>=0; i--) {
		if(!used[i]) {
			used[i] = true;
			order[ind] = i;
			if(ind == 0)
				dfs(ind+1, currK);
			else {
				int d = 1000000000;
				for(int j=0; j<M; j++)
					d = min(d, abs(a[order[ind-1]][j]-a[order[ind]][j]));
				dfs(ind+1, min(currK, d));
			}
			used[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin >> a[i][j];

	dfs(0, 1000000000);

	if(bestK == 1000000000)
		cout << 0 << endl;
	else
	cout << bestK << endl;
}
