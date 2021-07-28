#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 55

using namespace std;

int col[MAX_N];
vector <int> con[MAX_N];
int N, M;
vector <int> G[MAX_N];
bool picked[MAX_N];
int wins[MAX_N];

long long dfs(int cc, int ind) {
    if(ind >= con[cc].size()) {
        //for(int i=0; i<N; i++)
          //  cout << picked[i] << " \n"[i==N-1];
        return 1;
    }

    long long ret = 0;

    bool pos = true;
    for(int v : G[con[cc][ind]]) {
        if(v >= con[cc][ind]) break;
        if(picked[v]) {pos = false; break;}
    }
    if(pos) {
        picked[con[cc][ind]] = true;
        ret += dfs(cc, ind+1);
        picked[con[cc][ind]] = false;
    }
    if(wins[con[cc][ind]] < (int) G[con[cc][ind]].size()) {
        for(int v : G[con[cc][ind]]) {
            if (v <= con[cc][ind])
                break;
            wins[v] ++;
        }
        ret += dfs(cc, ind+1);
        for(int v : G[con[cc][ind]]) {
            if (v <= con[cc][ind])
                break;
            wins[v] --;
        }
    }

    return ret;
}

void DFS(int ind, int color) {
    col[ind] = color;
    con[color].push_back(ind);

    for (int i = 0; i < G[ind].size(); i ++) {
        if (!col[G[ind][i]]) {
            DFS(G[ind][i], color);
        }
    }
}

int main() {
    cin >> N >> M;
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }

    int c = 1;
    for (int i = 0; i < N; i ++) {
        if (!col[i]) {
            DFS(i, c);
            c ++;
        }
    }

    long long ans = 1;
    for(int cc = 1; cc < c; cc++) {
        sort(con[cc].begin(), con[cc].end());
        ans *= dfs(cc, 0);
    }

    cout << ans << endl;
}