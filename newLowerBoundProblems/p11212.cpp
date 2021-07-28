#include <iostream>
#include <queue>
#include <bitset>
#include <vector>
#include <unordered_map>

#define MAX_M 10000000000ll
#define f first
#define s second

using namespace std;

typedef pair<vector<long long>, long long> ii;

long long N, ans;
vector <long long> arr(10);
vector <long long> fin = {1,2,3,4,5,6,7,8,9,10};
bitset<MAX_M> vis;
bitset<MAX_M> start;
unordered_map<long long, bool> dist;
queue<ii> Q;

long long hsh(vector<long long> c) {
    long long ret = 0;
    for(int i=0; i<N; i++) {
        ret *= 10;
        ret += (c[i]-1);
    }
    return ret;
}

long long push_next() {
    vector <long long> c = Q.front().f;
    vector <long long> shifted(15);
    long long n = Q.front().s;
    long long s1 = start[hsh(c)];

    for(int a=0; a<N; a++) {
        for(int b=a; b<N; b++) {
            for(int k=0; k<=N; k++) {
                if(k <= b && k >= a) continue;

                long long ind = 0;
                for(int i=0; i<N; i++) {
                    if(i<=b && i>=a) continue;

                    if(i != k) {
                        shifted[ind] = c[i];
                        ind++;
                    } else {
                        for(int j=a; j<=b; j++) {
                            shifted[ind] = c[j];
                            ind++;
                        }
                        shifted[ind] = c[i];
                        ind++;
                    }
                }

                if(k == N) {
                    for(int j=a; j<=b; j++) {
                        shifted[ind] = c[j];
                        ind++;
                    }
                }

                if(ind != N) cout << "WRONG INDEX" << endl; // debug

                long long m = hsh(shifted);
                long long s2 = start[m];
                if(!vis[m]) {
                    vis.flip(m);
                    start[m] = s1;
                    Q.push(ii(shifted, n+1));
                    dist[m] = n+1;
                } else if(start[m] != s1) {
                    ans = dist[m] + n;
                    return 0;
                }
            }
        }
    }

    return 0;
}

int main() {
    while(true) {
        cin >> N;
        if (N == 0) return 0;

        for (int i = 0; i < N; i++)
            cin >> arr[i];

        vis.reset();
        start.reset();
        ans = -1;
        cout << "here" << endl;

        Q.push(ii(arr, 0));
        Q.push(ii(fin, 0));
        vis.flip(static_cast<size_t> (hsh(arr)));
        start.flip(static_cast<size_t> (hsh(arr)));
        vis.flip(static_cast<size_t> (hsh(fin)));

        while(ans == -1) {
            push_next();
        }

        cout << ans << endl;
    }
}