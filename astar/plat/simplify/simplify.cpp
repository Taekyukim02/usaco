#include <iostream>
#include <algorithm>
#include <map>
#define f first
#define s second
#define MOD 1000000007ll

using namespace std;

typedef pair<int,int> ii;
typedef pair<int, ii> pii;

int N, M;
pii edges[100000];

int par[40001];
int find_parent(int n) {
	if(par[n] == n)
		return n;
	return par[n] = find_parent(par[n]);
}
void build() {
	for(int i=0; i<=N; i++)
		par[i] = i;
}

int main() {
	// read input
	cin >> N >> M;
	for(int i=0; i<M; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		edges[i] = pii(d, ii(a, b));
	}

	// sort edges
	sort(edges, edges+M);

	// build DSU
	build();

	// MST algorithm
	long long len = 0;
	long long ans = 1;
	for(int i=0; i<M; ) {
		pii cand[3];
		int num = 1;
		cand[0] = edges[i++];
		while(edges[i].f == cand[0].f)
			cand[num++] = edges[i++];

		map <ii, int> cnt;
		map <int, int> nodes;
		int bad = 0;
		for(int j=0; j<num; j++) {
			if(find_parent(cand[j].s.f) != find_parent(cand[j].s.s)) {
				if(cnt.find(ii(find_parent(cand[j].s.f), find_parent(cand[j].s.s))) == cnt.end()) {
					cnt[ii(find_parent(cand[j].s.f), find_parent(cand[j].s.s))] = 1;
					cnt[ii(find_parent(cand[j].s.s), find_parent(cand[j].s.f))] = 1;
				} else {
					cnt[ii(find_parent(cand[j].s.f), find_parent(cand[j].s.s))]++;
					cnt[ii(find_parent(cand[j].s.s), find_parent(cand[j].s.f))]++;
				}

				nodes[find_parent(cand[j].s.f)] = 1;
				nodes[find_parent(cand[j].s.s)] = 1;
			}
			else {
				bad++;
			}
		}

		// get max included component
		int m = 0;
		for(pair<ii, int> n : cnt)
			m = max(m, n.s);

		// cases
		if(m > 1)
			ans = (ans*m) % MOD;
		else if(nodes.size() == 3 && num-bad==3)
			ans = (ans*3) % MOD;

		// combine DSU
		for(int j=0; j<num; j++) {
			pii e = cand[j];
			if(find_parent(e.s.f) != find_parent(e.s.s)) {
				par[find_parent(e.s.f)] = find_parent(e.s.s);
				len += e.f;
//				cout << "added edge between " << e.s.f << " " << e.s.s << "  length " << e.f << endl;
//				for(int k=1; k<=N; k++)
//					cout << find_parent(k) << " \n"[k==N];
			}
		}
	}

	cout << len << " " << ans << endl;
}
