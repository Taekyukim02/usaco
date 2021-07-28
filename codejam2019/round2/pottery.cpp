#include <iostream>
#include <vector>

using namespace std;

long long T, N, C[300], J[300];
int cnt = 0;

int main() {
    cin >> T;
    for(int ii=0; ii<T; ii++) {
        cin >> N;
        for(int i=0; i<N; i++) {
            cin >> C[i] >> J[i];
        }

        cnt = 0;
        recurse(0, 1, 0);

        cout << cnt << endl;
    }
}
}