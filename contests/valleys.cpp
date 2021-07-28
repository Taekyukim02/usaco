#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>

#define MAX_N 755
#define MAX_V 1000005
#define INF 987654321
#define f first
#define s second

using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii > pii;

int N, grid[MAX_N][MAX_N], val[MAX_N][MAX_N];
int dsu[MAX_V], sze[MAX_V];
pii order[MAX_N];
long long ans = 0;

int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0,  0, 1,-1, 1,-1,  1, -1};

void build() {
    for (int i = 0; i <= MAX_V; i++) {
        dsu[i] = i;
        sze[i] = 1;
    }
}
int rep(int n) {
    if(dsu[n] == n)
        return n;

    return (dsu[n] = rep(dsu[n]));
}
bool same(int a, int b) {
    return (rep(a) == rep(b));
}
void combine(int a, int b) {
    sze[rep(b)] += sze[rep(a)];
    dsu[rep(a)] = rep(b);
}

bool ok[MAX_N][MAX_N], visited[MAX_N][MAX_N];
void dfs(int x, int y, int v) {
    if(x < 0 || y < 0 || x >= N || y >= N
        || visited[x][y] || same(grid[x][y], v))
        return;

    ok[x][y] = true;
    visited[x][y] = true;
    for(int i=0; i<8; i++)
        dfs(x+dx[i], y+dy[i], v);

}

void floodfill(int v) {
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++) {
            ok[i][j] = false;
            visited[i][j] = false;
        }

    for(int i=0; i<N; i++) {
        dfs(i, N - 1, v);
        dfs(N - 1, i, v);
        dfs(i, 0, v);
        dfs(0, i, v);
    }
}

int main() {
    ifstream fin("valleys.in");
    fin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fin >> grid[i][j];
            order[i * N + j] = pii(grid[i][j], ii(i, j));
        }
    }
    fin.close();

    /*
    // create value[]
    priority_queue <pii> Q;
    for(int i=0; i<N; i++) {
        val[0][i] = val[i][0] =
                val[i][N-1] = val[N-1][i] = INF;
        Q.push(pii(grid[i][N-1], ii(i, N-1)));
        Q.push(pii(grid[N-1][i], ii(N-1, i)));
        Q.push(pii(grid[i][  0], ii(i,   0)));
        Q.push(pii(grid[0][  i], ii(0,   i)));
    }
    while(!Q.empty()) {
        int v = Q.top().f;
        ii loc = Q.top().s;
        Q.pop();

        int x1, y1;
        for(int i=0; i<8; i++) {
            x1 = loc.f + dx[i];
            y1 = loc.s + dy[i];

            if(val[x1][y1] < v) {
                Q.push(pii(min(v, grid[x1][y1]), ii(x1, y1)));
                val[x1][y1] = v;
            }
        }
    }

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cout << value[i][j] << " \n"[j==N-1];


    // create dec array
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            decr[i*N+j] = ii(val[i][j], grid[i][j]);
    sort(decr, decr+N*N);
    reverse(decr);
    */

    // Do process
    sort(order, order+N*N);

    build();
    int idx = 0;
    for(int k=0; k<N*N; k++) {
        pii l = order[k];
        int v = l.f;
        ii loc = l.s;

        // combine
        int x1, y1;
        for(int i=0; i<4; i++) {
            x1 = loc.f + dx[i];
            y1 = loc.s + dy[i];
            if(x1 >= 0 && y1 >= 0 && x1 < N && y1 < N
                && grid[x1][y1] < v
                && !same(grid[x1][y1], v))
                 combine(grid[x1][y1], v);
        }

        bool flag = false;
        floodfill(v);
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++) {
                cout << ok[i][j] << " \n"[j==N-1];
                flag |= !(same(grid[i][j], v) | ok[i][j]);
            }

        if(!flag)
            ans += sze[rep(v)];
    }

    ofstream fout ("valleys.out");
    fout << ans << endl;
    fout.close();
}