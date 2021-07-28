#include <iostream>
#include <vector>
#include <map>
#define MAX_E 100000			// max number of events (compressed coordinates)

using namespace std;

map <long long, long long> mp;
vector <long long> a, b, h;
long long segtree[3*MAX_E]; 	// contains max height in each interval
long long lazy[3*MAX_E];
long long toUpdateLazy[3*MAX_N];
long long event[MAX_E];			// contains actual heights at events

// finish lazy propogation
void down(int node, long long l, long long r) {

}

// updates the segment tree
void update(int node, long long l, long long r, long long q1, long long q2, long long h) {
	if(l>r || q1>q2 || l>q2 || r<q1)
		return;
	if(q1 <= l && r <= q2) {
		lazy[node] = h;
		toUpdateLazy[node] = true;
		return;
	}

	down(node, l, r);

	long long mid = (l+r)/2;
}

// get max distance such that max height upto that point is less or equal to h
long long get(int node, long long l, long long r, long long h) {
	down(node, l, r);
	if(segtree[node] <= h) return mp[r];
	if(l==r) {
		return mp[l-1] + ((h-event[l-1]) / ((event[l]-event[l-1])/(mp[l]-mp[l-1]));	// math expression
	}
	else if(segtree[2*node] > h)
		return get(2*node, l, (l+r)/2, h);
	else {
		return get(2*node+1, (l+r)/2+1, r, h);
	}
}

int main()
{	
	int N, Q=0;
	vector <char> t;
	set <long long> actualCoord;
	actualCoord.insert(1);
	actualCoord.insert(N);

	cin >> N;
	while(true) {
		char x;
		cin >> x;
		if(x == 'I') {
			long long i, j, k;
			cin >> i >> j >> k;
			a.push_back(i);
			b.push_back(j);
			h.push_back(k);
			actualCoord.insert(i);
			actualCoord.insert(b);
			Q++;
		} else if(x == 'Q') {
			int i;
			cin >> i;
			a.push_back(0);
			b.push_back(0);
			h.push_back(i);
			Q++;
		} else break;
	}

	// coordinate compression
	long long index = 1;
	for(long long v : actualCoord) mp[v] = 1;
	for(auto it = mp.begin(); it != mp.end(); it++)
		*it = index++;

	// take insertions and queries
	for(int i=0; i<Q; i++) {
		if(t[i] == 'I') {
			update(1, 1, mp.size(), a[i], b[i], h[i]);
		} else {
			cout << get(1, 1, mp.size(), h[i]) << endl; 
		}
	}

	return 0;
}
