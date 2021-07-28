#include <iostream>

using namespace std;

bool used[10];
int which[10];
int N, tSum;
bool solved;
int pas[10][10];

void makePas() {
	pas[0][0] = 1;
	for(int i=1; i<N; i++)
		for(int j=0; j<=i; j++)
			pas[i][j] = pas[i-1][j] + pas[i-1][j-1];
}

void solve() {
	int s=0;
	for(int i=0; i<N; i++)
		s += pas[N-1][i] * which[i];

	if(s == tSum) {
		for(int i=0; i<N; i++)
			cout << which[i] << " ";
		cout << endl;
		solved = true;
	}
}

void dfs(int numUsed) {
	if(solved) return;
	if(numUsed == N) {
		solve();
		return;
	}

	for(int i=0; i<N; i++) {
		if(!used[i]) {
			used[i] = true;
			which[numUsed] = i+1;
			dfs(numUsed+1);
			which[numUsed] = 0;
			used[i] = false;
		}
	}
}

int main() {
	cin >> N >> tSum;
	makePas();

	// dfs
	dfs(0);

	// done
	return 0;
}
