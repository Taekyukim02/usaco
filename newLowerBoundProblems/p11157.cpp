#include <iostream>

#define f first
#define s second

using namespace std;

typedef pair<long long, int> ii;

ii arr[105];
int N, D;
char a;

bool possible (int d) {
    int used[105];
    for(int i=0; i<105; i++)
        used[i] = 0;

    int currI = 0;
    int nextI = 0;
    long long pos = 0;
    // 0 to D and back
    while(pos < D) {
        nextI = currI + 1;
        if(arr[nextI].f - pos > d) {
            return false;
        }

        int test = nextI;
        while(test <= N+1 && arr[test].f - pos <= d) {
            nextI = test;
            test++;
        }
        used[nextI] = 1;
        pos = arr[nextI].f;
        currI = nextI;
    }
    while(pos > 0) {
        nextI = currI - 1;
        int test = nextI;
        while(test >= 0 && pos - arr[test].f <= d) {
            if(!(arr[test].s == 'S' && used[test]))
                nextI = test;
            test--;
        }
        if(pos - arr[nextI].f > d || ((arr[nextI].s == 'S') && used[nextI]))
            return false;
        pos = arr[nextI].f;
        currI = nextI;
    }

    return true;
}

int main() {
    int T; cin >> T;
    for(int j=1; j<=T; j++) {
        cin >> N >> D;
        for(int i=1; i<=N; i++) {
            cin.get(a);
            cin.get(a); arr[i].s = a;
            cin.get(a);
            cin >> arr[i].f;
        }
        arr[0] = ii(0, 'B');
        arr[N+1] = ii(D, 'B');

        int l = 1;
        int r = D;
        while(l < r) {
            int mid = (l+r)/2;
            if(possible(mid)) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        cout << "Case " << j << ": " << l << endl;
    }
}