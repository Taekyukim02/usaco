#include <iostream>
#include <algorithm> 
#include <stack>

using namespace std;

typedef pair<int,int> ii;

bool used[501][501];
long long binom[501][501];

int dr[6] = {-1, -1, 0, 0, 1, 1};
int dc[6] = {-1, 0, -1, 1, 0, 1};
int arr[6] = {0,1,2,3,4,5};
stack <ii> st;

bool recurse(int r, int c, int N, int s) {
	if(r < 1 || c < 1 || c > r || N < 0 || s <= 0)
		return false;

	N -= binom[r-1][c-1];
	s -= 1;
	if(N == 0) {
		st.emplace(r, c);
		return true;
	}
	if(s == 0)
		return false;
	
	used[r][c] = 1;
	random_shuffle(arr, arr+6);
	for(int i=0; i<6; i++) {
		int newr = r + dr[arr[i]];
		int newc = c + dc[arr[i]];
		if(!used[newr][newc]) {
			bool res = recurse(newr, newc, N, s);
			if(res) {
				st.emplace(r, c);
				used[r][c] = 0;
				return true;
			}
		}
	}
	used[r][c] = 0;
	return false;
}

void solve() {
	int N; cin >> N;
	recurse(1,1,N,500);
	while(!st.empty()) {
		ii a = st.top();
		cout << a.first << " " << a.second << endl;
		st.pop();
	}
}

int main() {
	binom[0][0] = 1;
	for(int i=1; i<501; i++) {
		binom[i][0] = binom[i][i] = 1;
		for(int j=1; j<i; j++)
			binom[i][j] = binom[i-1][j-1] + binom[i-1][j];
	}

	int T; cin >> T;
	for(int t=1; t<=T; t++) {
		cout << "Case #" << t << ":" << endl;
		solve();
	}
}
