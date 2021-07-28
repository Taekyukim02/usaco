#include <iostream>
#include <algorithm>
#include <set>
#define MAX_N 100000
#define f first
#define s second

using namespace std;

typedef pair<int,int> ii;

int C[MAX_N];
int segtree[3*MAX_N];
int lazy[3*MAX_N];

void build(int l, int r, int n) {
	if(l==r) {
		segtree[n] = C[l];
		return;
	}
	int mid = (l+r)/2;
	build(l, mid, 2*n);
	build(mid+1, r, 2*n+1);
	segtree[n] = min(segtree[2*n], segtree[2*n+1]);
	return;
}

int getMin(int l, int r, int q1, int q2, int n) {
	if(l>r || q1>q2 || q2<l || r<q1)
		return 1000000000;

	if(lazy[n] != 0) {
		segtree[n] -= lazy[n];
		if(l!=r) {
			lazy[2*n] += lazy[n];
			lazy[2*n+1] += lazy[n];
		}
		lazy[n] = 0;
	}

	if(q1 <= l && r <= q2) {
		return segtree[n];
	}
	int mid = (l+r)/2;
	return min(getMin(l, mid, q1, q2, 2*n)
				, getMin(mid+1, r, q1, q2, 2*n+1) );
}

void update(int l, int r, int q1, int q2, int n) {
	if(lazy[n] != 0) {
		segtree[n] -= lazy[n];
		if(l!=r) {
			lazy[2*n] += lazy[n];
			lazy[2*n+1] += lazy[n];
		}
		lazy[n] = 0;
		return;
	}

	if(l>r || q1>q2 || q2<l || r<q1)
		return;
	if(q1 <= l && r <= q2) {
		segtree[n]--;
		if(l!=r) {
			lazy[2*n]++;
			lazy[2*n+1]++;
		}
		lazy[n] = 0;
		return;
	}
	int mid = (l+r)/2;
	update(l, mid, q1, q2, 2*n);
	update(mid+1, r, q1, q2, 2*n+1);
	segtree[n] = min(segtree[2*n], segtree[2*n+1]);
}

int main() {
	// read input
	int N, M;
	cin >> N >> M;

	for(int i=0; i<N; i++)
		cin >> C[i];

	build(0, N-1, 1);
	ii p[MAX_N];
	for(int i=0; i<M; i++) {
		cin >> p[i].s >> p[i].f;
		p[i].f--;
		p[i].s--;
	}

	// sort by intervals by right endpoint
	sort(p, p+M);

	// go through every one of the endpoints
	int total = 0;
	for(int i=0; i<M; i++) {
		//cout << getMin(0, N-1, p[i].s, p[i].f, 1) << endl;
		if(getMin(0, N-1, p[i].s, p[i].f, 1) > 0) {
//			cout << p[i].s << " " << p[i].f << " is good" << endl;
			total++;
			update(0, N-1, p[i].s, p[i].f, 1);
		}
/*
		for(int i=0; i<20; i++) {
			cout << segtree[i] << " ";
		}
		cout << endl;
		*/
	}

	cout << total << endl;
}
