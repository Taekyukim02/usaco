#include <iostream>
#include <fstream>

#define MAX_N 1005
#define MOD 1000000007

using namespace std;

int N, M;
string str[MAX_N];
int cluster [MAX_N][MAX_N];
int point [MAX_N];
bool visited[MAX_N][MAX_N];
bool seen[MAX_N];

long long mypow(int a, int b) {
    if(b == 0) return 1;
    if(b == 1) return a;

    if(b%2 == 0) return mypow(a*a % MOD, b/2);
    if(b%2 == 1) return a*mypow(a*a % MOD, b/2) % MOD;
}
void dfs(int x, int y, int i, int k) {
    if(y < 0 || x < 0 || y >= M || x >= N ||
            visited[x][y] || str[x][y] == '#') return;

    visited[x][y] = true;
    cluster[x][y] = k;
//    cout << "at " << x << " " << y << " " << k << endl;

    if(x == i) {
        dfs(x, y-1, i, k);
        dfs(x, y+1, i, k);
        dfs(x+1, y, i, k);
    }
    if(x == i+1) {
        dfs(x, y-1, i, k);
        dfs(x, y+1, i, k);
        dfs(x-1, y, i, k);
    }
}

int main() {
    ifstream fin ("cave.in");
    cin >> N >> M;
    for(int i=0; i<N; i++)
        cin >> str[i];
    fin.close();

    int num = 1;
    for(int i=1; i<M-1; i++) {
        if(str[N-2][i] == '.')
            cluster[N - 2][i] = num;
        else
            num++;
    }

    long long ans = 0;
    for(int i=N-2; i>0; i--) {
        for(int j=0; j<M; j++) {
            visited[i][j] = false;
        }

        for(int j=0; j<M; j++) {
            if(!visited[i+1][j] && str[i+1][j] == '.')
                dfs(i+1, j, i, cluster[i+1][j]);
        }

        int cnt = 0;
        for(int j=0; j<MAX_N; j++)
            seen[j] = false;
        for(int j=0; j<M; j++) {
            if(!seen[cluster[i][j]] && str[i][j] == '.') {
                seen[cluster[i][j]] = 1;
                cnt ++;
            }
        }
        ans += mypow(2, cnt) - 1;
//        cout << "debug = " << cnt << " " << ans << endl;
    }

    ofstream fout ("cave.out");
    cout << ans + 1 << endl;
    fout.close();

    /*
    for(int i=0; i<N; i++) {
        for (int j = 0; j < M; j++)
            cout << cluster[i][j] << " ";
        cout << endl;
    }
     */
}