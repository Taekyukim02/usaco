#include <iostream>
#include <fstream>
#include <vector>

#define MAX_N 100005
#define MAX_C 100005

using namespace std;

int N, Q;
int query[2*MAX_N][3];
vector <int> G[MAX_N];
int pre[MAX_N];
bool used[MAX_C];   // used colors
long long answer[2*MAX_N];
int color[MAX_N];   // current color
long long sum[MAX_N];

void dfs(int i, int p) {
    pre[i] = p;
    for(int v : G[i])
        if(v != p)
            dfs(v, i);
}

void propUp(int v, long long delta) {
    if(v == 0) return;
    sum[v] += delta;
    propUp(pre[v], delta);
}

// update vertex v with color c
void update(int v, int c, int depth) {
    if(color[v] != c) {
        long long f = sum[v];
        color[v] = c;
        sum[v] = 1;
        for(int u : G[v]) {
            if (u != pre[v]) {
                update(u, c, depth+1);
                sum[v] += sum[u];
            }
        }
        if(depth == 0)
            propUp(pre[v], sum[v] - f);
    }
}

int main() {
    ifstream fin ("snowcow.in");

    fin >> N >> Q;
    for(int i=0; i<N-1; i++) {
        int a, b;
        fin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(1, 0);

    for(int i=0; i<Q; i++) {
        fin >> query[i][0] >> query[i][1];
        if (query[i][0] == 1) {
            fin >> query[i][2];
            used[query[i][2]] = true;
        }
    }
    fin.close();

    for(int c=0; c<MAX_C; c++) {
        if(used[c]) {
            for (int i = 1; i <= N; i++)
                sum[i] = 0;

            for (int i = 0; i < Q; i++) {
                if(query[i][0] == 1 && query[i][2] == c) {
                    update(query[i][1], c, 0);
                } else if(query[i][0] == 2) {
                    answer[i] += sum[query[i][1]];
                }
            }
        }
    }

    ofstream fout ("snowcow.out");
    for(int i=0; i<Q; i++)
        if(query[i][0] == 2)
            fout << answer[i] << endl;
    fout.close();
}