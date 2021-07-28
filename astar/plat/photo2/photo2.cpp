#include <iostream>
#include <algorithm>
#include <map>

#define MAX_N 200005
#define MAX_M 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

int N, M;
int dp[MAX_N];
ii photo[MAX_M];
map <int, int> S;

void solve() {
	int lPtr = 0, rPtr = 0;
	int lIdx = 0, rIdx = 0;
	int bestDp = 0;
	S[0] = 1;
	for(int i=1; i<=N+1; i++) {
		int prevLIdx = photo[lPtr-1].s;
		int prevRIdx = photo[lPtr].f;

		// remove intervals
		while(lPtr < M && photo[lPtr].s < i) {
			lPtr++;
		}

		// update S values
		while(prevLIdx < photo[lPtr-1].f) {
			if(S[dp[prevLIdx]] == 1)
				S.erase(dp[prevLIdx]);
			else
				S[dp[prevLIdx]]--;

			prevLIdx++;
		}
		while(prevRIdx < photo[lPtr].f) {
			if(S.find(dp[prevRIdx]) == S.end())
				S[dp[prevRIdx]] = 1;
			else
				S[dp[prevRIdx]]++;

			prevRIdx++;
		}
		if(!S.empty() || photo[lPtr-1].s >)
			dp[i] = (--S.end())->f + 1;
		else
			dp[i] = 0;

		cout << i << " " << prevLIdx << " " << prevRIdx << endl;
	}
}

int main() {
	cin >> N >> M;
	for(int i=0; i<M; i++)
		cin >> photo[i].f >> photo[i].s;
	
	sort(photo, photo+M);

	solve();

	for(int i=0; i<N+2; i++)
		cout << dp[i] << " ";
	cout << endl;

	cout << dp[N+1]-1 << endl;
}
