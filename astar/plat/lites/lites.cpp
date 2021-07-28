#include <iostream>
#define MAX_N 100000

using namespace std;

int segtree[3*MAX_N];
int lazy[3*MAX_N];

void down(int node, int l, int r) {
	if(lazy[node]%2 == 0) return;

	lazy[node] = 0;
	lazy[2*node]++;
	lazy[2*node+1]++;

	int mid = (l+r)/2;
	segtree[2*node] = mid-l+1 - segtree[2*node];
	segtree[2*node+1] = r-mid - segtree[2*node+1];
}

void toggle(int node, int l, int r, int q1, int q2) {
	if(l>r || q1>q2 || q2<l || q1>r)
		return;
	if(q1 <= l && r <= q2) {
		segtree[node] = r-l+1-segtree[node];
		lazy[node]++;
		return;
	}
	
	down(node, l, r);
	int mid = (l+r)/2;
	toggle(2*node  ,     l, mid, q1, q2);
	toggle(2*node+1, mid+1,   r, q1, q2);
	segtree[node] = segtree[2*node] + segtree[2*node+1];
}

int get(int node, int l, int r, int q1, int q2) {
	if(l>r || q1>q2 || q2<l || r<q1)
		return 0;
	if(q1 <= l && r <= q2)
		return segtree[node];
	
	down(node, l, r);
	int mid = (l+r)/2;
	return get(2*node  ,    l, mid, q1, q2)
			+  get(2*node+1, mid+1,   r, q1, q2);
}

int main()
{
	int N, M; 
	cin >> N >> M;

	int a[100000], b[100000], c[100000];
	for(int i=0; i<M; i++)
		cin >> a[i] >> b[i] >> c[i];
	
	for(int i=0; i<M; i++) {
		if(a[i] == 0) {
			toggle(1, 1, N, b[i], c[i]);
//  		cout << endl;
//  		for(int j=1; j<10; j++)
//  			cout << segtree[j] << " ";
//  		cout << endl;
		}
		else
			cout << get(1, 1, N, b[i], c[i]) << endl;
	}

	return 0;
}
