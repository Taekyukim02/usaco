#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>

using namespace std;

void fastscan(int &number)
{
    //variable to indicate sign of input number 
    bool negative = false;
    register int c;

    number = 0;

    // extract current character from buffer 
    c = getchar();
    if (c=='-')
    {
        // number is negative 
        negative = true;

        // extract the next character from the buffer 
        c = getchar();
    }

    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

    // if scanned input has a negative sign, negate the 
    // value of the input number 
    if (negative)
        number *= -1;
}

#define MAX_N 100005

int N;
long long a[MAX_N], k[MAX_N];
long long preK[MAX_N], pre2K[MAX_N];
long long segtree[4*MAX_N];
long long lazy[4*MAX_N];

long long getSum(int node, int l, int r, int q1, int q2) {
	if(l > r || q2 < l || r < q1 || q1 > q2)
		return 0;

	dolazy(node, l, r);

	if(q1 <= l && r <= q2)
		return segtree[node];
	
	int mid = (l+r)/2;
	return getSum(2*node, l, mid, q1, q2)
			+ getSum(2*node+1, mid+1, r, q1, q2);
}

long long dolazy(int node, int l, int r) {

}

long long evaluate(int node, int l, int r, int t) {

}

void update(int node, int l, int r, int q1, int q2, long long ai, int i) {
	if(l > r || q1 > q2 || r < q1 || q2 < l)
		return;
	if(q1 <= l && r <= q2) {
		segtree[node] = // TODO
		lazy[node] = ii(ai, i);
		return 0;
	}
	
	int mid = (l+r)/2;
	update(2*node, l, mid, q1, q2, ai, i);
	update(2*node+1, mid+1, r, q1, q2, ai, i);
	return 0;
}

// b-search for mx
int mysearch(long long ai, i) {
	int lo = i;
	int hi = N-1;
	while(lo < hi) {
		int mid = (lo+hi)/2;
		if(a[mid] >= ai + preK[mid-1]-pre[i-1])
			hi = mid;
		else
			lo = mid+1;
	}
	return lo;
}

int main() {
	fastscan(N);
	for(int i=0; i<N; i++)
		fastscan(a[i]);
	for(int i=0; i<N-1; i++)
		fastscan(k[i]);
	fastscan(Q);

	// get prefix sums of array k
	preK[0] = k[0];
	for(int i=1; i<N-1; i++)
		preK[i] = preK[i-1] + k[i];
	pre2K[0] = preK[0];
	for(int i=1; i<N-1; i++)
		pre2K[i] = pre2K[i-1] + preK[i];

	// process queries
	for(int i=0; i<Q; i++) {
		char c;
		int x, y;
		cin >> c;
		fastscan(x);
		fastscan(y);
		if(c == 's') {	// sum query
			cout << getSum(1, 0, N-1, x-1, y-1) << endl;
		} else { 		// update query
			a[x-1] += y;
			int mx = mysearch(a[x-1], x-1); 
			update(1, 0, N-1, x, mx, a[x-1], x-1);
		}
	}

	return 0;
}
