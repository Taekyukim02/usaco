#include <iostream>
#include <vector>

using namespace std;

long long T, N, C[305], J[305];
bool visited[305];
int cnt = 0;
long double ep = 0.000000000001;

void recurse(long double lo, long double hi, int idx, int num) {
    if (num == N && lo < hi - ep) {
        cnt++;
        return;
    }

    if(lo >= hi + ep)
        return;

    for(int i=0; i<N; i++) {
        if (!visited[i]) {
            long double dC = C[idx] - C[i];
            long double dJ = J[i] - J[idx];
            visited[i] = true;
            if(dC > 0 && dJ >= 0)
                recurse(lo, min(hi, dJ/dC), i, num+1);
            if(dC < 0)
                recurse(max(lo, dJ/dC), hi, i, num+1);
            if(dC == 0 && dJ > 0)
                recurse(lo, hi, i, num+1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> T;
    for(int ii=1; ii<=T; ii++) {
        cin >> N;
        for(int i=0; i<N; i++) {
            cin >> C[i] >> J[i];
            visited[i] = false;
        }

        cnt = 0;
        for(int i=0; i<N; i++) {
            visited[i] = true;
            recurse(0L, 1000000000L, i, 1);
            visited[i] = false;
        }

        cout << "Case #" << ii << ": " << cnt << endl;
    }
}