#include <iostream>
#include <vector>
#define MAX_N 19
#define f first
#define s second

using namespace std;

typedef pair<int,int> ii;

int dp[MAX_N][1<<MAX_N];
vector <ii> graph[MAX_N];
int oo = 987654321;

int main() {
	// read input
	int N, M;
	cin >> N >> M;

	for(int i=0; i<M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a-1].push_back(ii(b-1,c));
		graph[b-1].push_back(ii(a-1,c));
	}

	// base case
	for(int i=0; i<N; i++) {
		for(int j=0; j<(1<<N); j++)
			dp[i][j] = oo;
		dp[i][1<<i] = 0;
	}

	// dp
	for(int j=0; j<(1<<N); j++)
		for(int i=0; i<N; i++) {
			// check valid
			if((1<<i) & j) {
				for(ii to : graph[i])
					dp[to.f][(1<<to.f) | j] = min(dp[to.f][(1<<to.f) | j], dp[i][j] + to.s);
			}
		}

	// get answer
	int ans = oo;
	for(int i=0; i<N; i++)
		ans = min(ans, dp[i][(1<<N)-1]);

	cout << ans << endl;
}
