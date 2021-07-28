#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector< vector<int> > mat;

#define Default 				// define Default
#define MAX_N 50005

mat segtree[4*MAX_N];		// define MAX_N
int N, K, A[MAX_N], Q;

// range query [q1, q2]
mat get(int node, int l, int r, int q1, int q2) {
    if(l > r || r < q1 || q2 < l)
        return mat(20, vector<int>(20));

    if(q1 <= l && r <= q2)
        return segtree[node];

    mat p1 = get(2*node+0, l, (l+r)/2+0, q1, q2);
    mat p2 = get(2*node+1, (l+r)/2+1, r, q1, q2);

    mat ret = mat(20, vector<int>(20));
    for(int i=0; i<K; i++) {
        int sum = 0;
        for (int j = i; j < K; j++) {
            sum += p1[i][j];
            for (int k = j; k < K; k++)
                ret[i][k] += sum * p2[j][k];
        }
    }

    for(int i=0; i<K; i++)
        for(int j=0; j<K; j++)
            ret[i][j] += p1[i][j] + p2[i][j];

    return ret;
}

// build tree
void build(int node, int l, int r) {
    if(l > r)
        return;

    if(l == r) {
        segtree[node] = mat(20, vector<int>(20));
        segtree[node][A[l]-1][A[l]-1] = 1;

        return;
    }
    build(2*node+0, l, (l+r)/2+0);
    build(2*node+1, (l+r)/2+1, r);
    mat p1 = segtree[2*node+0];
    mat p2 = segtree[2*node+1];

    segtree[node] = mat(20, vector<int>(20));
    for(int i=0; i<K; i++) {
        int sum = 0;
        for (int j = i; j < K; j++) {
            sum += p1[i][j];
            for (int k = j; k < K; k++)
                segtree[node][i][j] += sum * p2[j][k];
        }
    }

    for(int i=0; i<K; i++)
        for(int j=0; j<K; j++)
            segtree[node][i][j] += p1[i][j] + p2[i][j];
}

int main() {
    ifstream fin ("nondec.in");
    ofstream fout ("nondec.out");
    fin >> N >> K;
    for(int i=0; i<N; i++)
        fin >> A[i];

    // set up segtree
    build(1, 0, N-1);

    fin >> Q;
    for(int i=0; i<Q; i++) {
        int L, R; fin >> L >> R;

        mat g = get(1, 0, N-1, L-1, R-1);
        long long ans = 0;
        for(int k=0; k<K; k++) {
            for (int j = 0; j < K; j++) {
//                cout << g[k][j] << " ";
                ans += g[k][j];
            }
//            cout << endl;
        }

        fout << ans + 1 << endl;
    }

    fin.close();
    fout.close();
}