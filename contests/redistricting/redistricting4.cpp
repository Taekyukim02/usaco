#include <iostream>
#include <fstream>

#define MAX_N 300005

using namespace std;

long long segtree[4*MAX_N];		// define MAX_N

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

int N, K;
string str;

int main() {
    ifstream fin ("redistricting.in");
    fin >> N >> K;
    fin >> str;


}