#include <iostream>

using namespace std;

#define Default 				// define Default
long long segtree[4*MAX_N];		// define MAX_N
long long lazy[4*MAX_N];
long long arr[MAX_N];

// point update on x
void update(int node, int l, int r, int x, int val) {
	if(x < l || r < x)
		return;
	if(l == r && l == x) {
		segtree[node] = val;
		return;
	}
	
	update(2*node+0, l, (l+r)/2+0, x, val);
	update(2*node+1, (l+r)/2+1, r, x, val);
	segtree[node] = segtree[2*node] + segtree[2*node+1];
}

// propagate lazy from node
void propagate(int node, int l, int r) {
	if(lazy[node] == Default)
		return;
	segtree[node] += lazy[node];
	if(l != r) {					// check how to update lazy[]
		lazy[2*node+0] += lazy[node];
		lazy[2*node+1] += lazy[node];
	}
	lazy[node] = Default;
}

// lazy-fill [q1, q2] range
void fill(int node, int l, int r, int q1, int q2, long long val) {
	propagate(node, l, r);			// might not need this line
	if(l > r || r < q1 || q2 < l)
		return;
    if(q1 <= l && r <= q2) {
		lazy[node] = val;
		propagate(node, l, r);		// updates segtree[node]
		return;
	}
	fill(2*node+0, l, (l+r)/2+0, q1, q2, val);
	fill(2*node+1, (l+r)/2+1, r, q1, q2, val);
	segtree[node] = segtree[2*node] + segtree[2*node+1];
}

// range query [q1, q2]
long long get(int node, int l, int r, int q1, int q2) {
	if(l > r || r < q1 || q2 < l)
		return 0;

	propagate(node, l, r);
	if(q1 <= l && r <= q2)
		return segtree[node];
	long long p1 = get(2*node+0, l, (l+r)/2+0, q1, q2);
	long long p2 = get(2*node+1, (l+r)/2+1, r, q1, q2);
	return (p1 + p2);
}

// build tree
long long build(int node, int l, int r) {
	if(l > r)
		return;

	lazy[node] = Default;
	if(l == r) {
		segtree[node] = arr[l];
		return segtree[node];
	}
	long long p1 = build(2*node+0, l, (l+r)/2+0);
	long long p2 = build(2*node+1, (l+r)/2+1, r);

	return segtree[node] = p1 + p2;
}
