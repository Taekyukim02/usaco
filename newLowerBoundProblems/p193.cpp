#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector <int> G[105];
bool black[105];
int bNum;
bool best[105];

int backtrack(int d) {
    if(d == N) {
        int cnt = 0;
        for(int i=0; i<N; i++)
            cnt += black[i];
        if(cnt > bNum) {
            bNum = cnt;
            for(int i=0; i<N; i++)
                best[i] = black[i];
        }
        return 0;
    }

    bool ok = true;
    for(int to : G[d])
        if(black[to] && to < d)
            ok = false;
    if(ok) {
        black[d] = 1;
        backtrack(d + 1);
        black[d] = 0;
    }
    backtrack(d + 1);
    return 0;
}

int main() {
    int T; cin >> T;
    while(T--) {
        cin >> N >> K;

        bNum = -1;
        for(int i=0; i<=N; i++) {
            G[i].clear();
            black[i] = 0;
        }

        for(int i=0; i<K; i++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        backtrack(0);

        cout << bNum << endl;
        for(int i=0; i<N; i++) {
            if(best[i]) {
                bNum--;
                cout << i + 1 << " \n"[bNum==0];
            }
        }
    }
}