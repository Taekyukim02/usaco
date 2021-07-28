#include <iostream>
#include <vector>

#define MAX_N 505
#define MAX_X 1030

using namespace std;

long long N, M;
long long grid[MAX_N][MAX_N];
long long path[MAX_N];
bool vis[MAX_N][MAX_X];

bool dfs(int i, int x) {
    vis[i][x] = true;

    if(i == 0 && x > 0) {
        return true;
    }
    else if (i == 0 && x <= 0)
        return false;

    i--;
    for(int j=0; j<M; j++)
        if(!vis[i][x^grid[i][j]]) {
            path[i] = j;
            bool res = dfs(i, x^grid[i][j]);
            if(res)
                return true;
        }
}

int main() {
    cin >> N >> M;
    for(int i=0; i<MAX_N; i++)
        for(int j=0; j<MAX_N; j++)
            grid[i][j] = 0;

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> grid[i][j];

    for(int i=0; i<MAX_N; i++) {
        path[i] = -1;
        for(int j=0; j<MAX_X; j++)
            vis[i][j] = false;
    }

    bool ret = dfs(N, 0);

    if(ret) {
        cout << "TAK" << endl;
        for(int i=0; i<N; i++)
            cout << path[i]+1 << " ";
        cout << endl;
    } else {
        cout << "NIE" << endl;
    }

    return 0;
}