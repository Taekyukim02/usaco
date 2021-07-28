#include <iostream>
#include <vector>
#define MOD 998244353ll

using namespace std;

vector <int> graph[300000];
int color[300000];
int odd, even;
bool bad;
long long powr[300001];

void dfs(int node, int c) {
	color[node] = c;
	if(c == 0) even++;
	else	   odd ++;

	for(int to : graph[node]) {
		if(color[to] == -1)
			dfs(to, 1-c);
		if((color[node] ^ color[to]) == 0)	
			bad = true;
	}
}

long long solve() {
	// read input
	int N, M;
	cin >> N >> M;

	for(int i=0; i<N; i++)
		graph[i].clear();

	for(int i=0; i<M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}

	for(int i=0; i<N; i++)
		color[i] = -1;

	long long ans = 1;
	for(int i=0; i<N; i++) {
		if(color[i] == -1) {
			bad = false;
			odd = even = 0;
			dfs(i, 0);
			if(!bad)
				ans = (ans * ((powr[odd] + powr[even]) % MOD) % MOD);
			else {
				ans = 0;
				break;
			}
		}
	}

	return ans;
}

int main() {
	int T;
	cin >> T;

	powr[0] = 1;
	for(int i=1; i<=300000; i++)
		powr[i] = 2*powr[i-1]%MOD;

	for(int i=0; i<T; i++) {
		cout << solve() << endl;
	}
	return 0;
}
