#include <iostream>

#define MAX_N 505
#define INF 987654321

using namespace std;

int N;
long long dp[MAX_N][MAX_N];

int main() {
    cin >> N;

    for(int i=0; i<MAX_N; i++)
        for(int j=0; j<MAX_N; j++)
            dp[i][j] = INF;

    for(int i=0; i<MAX_N-1; i++)
        dp[i][i] = dp[i][i+1] = 0;

    for(int d=2; d<N; d++) {
        for(int i=1; i+d<=N; i++) {
            for(int j=i; j<i+d-1; j++) {
                dp[i][i + d] = min(dp[i][i + d],
                        dp[i][j] + dp[j][i+d-1] + j*(i+d-1)*(i+d));
            }
        }
    }

    cout << dp[1][N] << endl;
}