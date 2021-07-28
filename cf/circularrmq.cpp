#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <sstream>
#include <istream>

#define MAX_N 200005
#define Default 0               // define Default
#define INF 987654321

using namespace std;

long long N, M;
char w[256];

long long arr[MAX_N];
long long segtree[4*MAX_N];     // define MAX_N
long long lazy[4*MAX_N];

// propagate lazy from node
void propagate(int node, int l, int r) {
    if(lazy[node] == Default)
        return;
    segtree[node] += lazy[node];
    if(l != r) {                    // check how to update lazy[]
        lazy[2*node+0] += lazy[node];
        lazy[2*node+1] += lazy[node];
    }
    lazy[node] = Default;
}

// lazy-fill [q1, q2] range
void fill(int node, int l, int r, int q1, int q2, long long val) {
    propagate(node, l, r);          // might not need this line
    if(l > r || r < q1 || q2 < l)
        return;
    if(q1 <= l && r <= q2) {
        lazy[node] = val;
        propagate(node, l, r);      // updates segtree[node]
        return;
    }
    fill(2*node+0, l, (l+r)/2+0, q1, q2, val);
    fill(2*node+1, (l+r)/2+1, r, q1, q2, val);
    segtree[node] = min(segtree[2*node], segtree[2*node+1]);
}

// range query [q1, q2]
long long get(int node, int l, int r, int q1, int q2) {
    if(l > r || r < q1 || q2 < l)
        return INF;
	propagate (node, l, r);
    if(q1 <= l && r <= q2)
        return segtree[node];
    long long p1 = get(2*node+0, l, (l+r)/2+0, q1, q2);
    long long p2 = get(2*node+1, (l+r)/2+1, r, q1, q2);
    return min(p1,  p2);
}

// build tree
long long build(int node, int l, int r) {
    if(l > r)
        return 0;

    lazy[node] = Default;
    if(l == r) {
        segtree[node] = arr[l];
        return segtree[node];
    }
    long long p1 = build(2*node+0, l, (l+r)/2+0);
    long long p2 = build(2*node+1, (l+r)/2+1, r);

    return segtree[node] = min(p1, p2);
}

void fastscan(long long &number)
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


int main() {
	fastscan(N);
	for(int i=0; i<N; i++)
		fastscan(arr[i]);
	build(1, 0, N-1);

	fastscan(M);
	for(int i=0; i<M; i++) {
		cin.getline(w, 256);
		stringstream in (w);
		long long a, b, c;
		in >> a >> b;
		if(in >> c) {	// update query
			if(a > b) {
				fill(1, 0, N-1, a, N-1, c);	
				fill(1, 0, N-1, 0, b, c);	
			} else {
				fill(1, 0, N-1, a, b, c);	
			}
		}
		else {			// get query
			if(a > b) {
				long long p1 = get(1, 0, N-1, a, N-1);	
				long long p2 = get(1, 0, N-1, 0, b);	
				cout << min(p1, p2) << endl;
			}
			else {
				cout << get(1, 0, N-1, a, b) << endl;	
			}
		}
	}

	return (0);
}



