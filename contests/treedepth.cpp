#include <iostream>
#include <fstream>
#include <math.h>

#define MAX_N 20

using namespace std;

int N, K;
long long M;
long long fact[MAX_N+6];

long long dp[1<<MAX_N][MAX_N+1];

int numBits(int i) {
    int ret = 0;
    while(i > 0) {
        ret += (i & 1);
        i >>= 1;
    }
    return ret;
}

long long calc(int L, int G, int T, int n) {
    if(G < (T-n)) return 0;
    long long ret = 1;
    for(int i=0; i<(T-n); i++) {
        ret *= G-i;
        ret %= M;
    }
    ret *= fact[n];
    ret %= M;

    return ret;
}

int main() {
    ifstream fin ("treedepth.in");
    ofstream fout ("treedepth.out");

    cin >> N >> K >> M;
    if(N > 20) return 0;

    fact[0] = 1;
    for(int i=1; i<MAX_N+6; i++)
        fact[i] = fact[i-1] * i % M;

    for(long long i=0; i<(1<<N); i++) {
        int T = numBits(i);
        int G = T;
        int L = 0;
        for(int x=0; x<N; x++) {
            if((i & (1<<x)) == 0) {   // unused
                for(int n=0; n<T; n++) {
                    dp[i | (1<<x)][n] += calc(L, G, T, n);
//                    cout << "goto " << (i | (1<<x)) << endl;
//                    cout << "calc("<<L<<" "<<G<<" "<<T<<" "<<n<<") = "<<calc(L, G, T, n) << endl;
                    dp[i | (1<<x)][n] %= M;
                }
                dp[i | (1<<x)][T] += fact[T]/fact[L] * (long long) pow(2, L);
            } else {
                G--;
                L++;
            }
        }
    }

    for(int j=0; j<(1<<N); j++) {
        cout << j << "  :  " << endl;
        for (int i = 0; i < N; i++) {
            cout << dp[j][i] << " \n"[i == N - 1];
        }
    }

    return 0;
}