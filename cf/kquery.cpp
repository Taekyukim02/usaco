#include <iostream>
#include <algorithm>
#define f first
#define s second

using namespace std;

typedef pair<long long,int> pi;
typedef pair<long long, long long> pl;
typedef pair<long long, pl> pll;
typedef pair<pll, int> plli;

int sum[90000];

void build(int l, int r, int n) {
	if(l==r) {
		sum[n] = 1;
		return;
	}
	int m = (l+r)/2;
	build(l,m,2*n);
	build(m+1,r,2*n+1);
	sum[n] = sum[2*n] + sum[2*n+1];
	return;
}

void set(int v, int l, int r, int n) {
	if(v<l || r<v)
		return;
	if(l==r) {
		sum[n] = 0;
		return;
	}
	int m = (l+r)/2;
	set(v,l,m,2*n);
	set(v,m+1,r,2*n+1);
	sum[n] = sum[2*n] + sum[2*n+1];
	return;
}

long long get(int l, int r, int q1, int q2, int n) {
	if(q2 < l || r < q1 || l > r || q1 > q2)
		return 0;
	if(q1 <= l && r <= q2)
		return sum[n];
	int m = (l+r)/2;
	return get(l,m,q1,q2,2*n) + get(m+1,r,q1,q2,2*n+1);
}

int main() {
	int N; cin >> N;
	pi arr[30000];
	for(int i=0; i<N; i++) {
		cin >> arr[i].f;
		arr[i].s = i;
	}
	int M; cin >> M;
	plli Q[200000];
	for(int i=0; i<M; i++) {
		cin >> Q[i].f.s.f >> Q[i].f.s.s >> Q[i].f.f;
		Q[i].f.s.f--;
		Q[i].f.s.s--;
		Q[i].s = i;
	}

	sort(arr, arr+N);
	sort(Q, Q+M);

	build(0, N-1, 1);
	int it = 0;
	int ans[200000];
	for(int i=0; i<M; i++) {
		while (it<N && arr[it].f <= Q[i].f.f) {
			set(arr[it].s, 0, N-1, 1);
			it++;
		}
		ans[Q[i].s] = get(0, N-1, Q[i].f.s.f, Q[i].f.s.s, 1);
	}

	for(int i=0; i<M; i++)
		cout << ans[i] << endl;
	return 0;
}
