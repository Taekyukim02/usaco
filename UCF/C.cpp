#include <iostream>
#include <vector>
#include <iomanip>

#define MAX_N 1005

using namespace std;

vector <int> G[MAX_N];
int conn[MAX_N];
bool visited[MAX_N];

void dfs(int i, int cnt) {
    if(visited[i]) return;
    visited[i] = 1;
    conn[cnt] ++;

    for(int v : G[i])
        dfs(v, cnt);
}

double find_answer(int n, int k) {
    if(n == 0 || k == 0) return 0;

    double ret = &memo[n][k];
    ret = find_answer(n-1, k-1) + find_answer(n, k);
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    for(int i=0; i<N; i++) {
        conn[i] = 0;
        visited[i] = 0;
        G[i].clear();
    }
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    int cnt = 0;

    for(int i=0; i<N; i++)
        if(!visited[i])
            dfs(i, ++cnt);

    cout << "Pond i: " << fixed << setprecision(3) << find_answer(N, K) << endl;
}