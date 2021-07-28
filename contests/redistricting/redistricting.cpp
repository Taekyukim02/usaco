#include <iostream>
#include <set>
#define f first
#define s second

using namespace std;

typedef pair<int,int> ii;

int N, K;
string dist;
int dp[100001];
int preG[100001];

set <ii> S;
int zero = 0;
int p1 = 0;
void create(int j) {
	int M = dp[p1];
	S.clear();
	zero = 0;
	if(p1 == 0)
		S.insert(ii(0, -1));
	while(dp[p1+1] == M && p1 < j) {
		S.insert(ii( 2*(preG[j]-preG[p1-1]) - (j-p1), p1) );
		p1++;
	}
}

void add(int i) {
	S.insert(ii(zero, i));
	p1++;
}

int get(int j) {
	while(!S.empty()) {
		auto it = S.front();
		ii x = *it;
		if(x.s + K < j) {
			S.erase(it);
			continue;
		}
		if(x.f < zero)
			return 0;
		return 1;
	}
	S.create(j);
	return 1;
}

int main() {
	cin >> N >> K;
	cin >> dist;

	preG[0] = (dist[0] == 'G');
	for(int i=1; i<N; i++)
		preG[i] = preG[i-1] + (dist[i] == 'G');
	
	for(int i=0; i<N; i++) {
		if(S.empty()) S.create(i);		

		dp[i+1] = dp[min(i+1-K, 0)] + get(i);

		zero = (zero+1 - 2*('G' == dist[i]));
		if(dp[i+1] == dp[max(i+1-K, 0)])
			add(i);
	}

	cout << dp[N] << endl;
}
