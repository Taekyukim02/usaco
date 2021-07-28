#include <iostream>

#define MAX_N 255
#define MAX_K 2505

using namespace std;

int N, K, arr[MAX_N];
long long dp[MAX_N][MAX_K];

int main() {
    cin >> N >> K;
    for(int i=1; i<=N; i++)
        cin >> arr[i];

    dp[0][0] = dp[1][0] = 1;
    for(int i=2; i<=N; i++) {
        for(int j=0; j<=K; j++) {
            int lft = i-1;
            int currMax = arr[i];
            int currMin = arr[i];
            int diff = currMax - currMin;
            while(lft >= 0 && diff <= j) {
                dp[i][j] += dp[lft][j-diff];

                currMax = max(currMax, arr[lft]);
                currMin = min(currMin, arr[lft]);
                diff = currMax - currMin;
                lft--;
            }
        }
    }

    for(int i=0; i<=N; i++)
        for(int j=0; j<=K; j++)
            cout << dp[i][j] << " \n"[j==K];

    long long ans = 0;
    for(int i=0; i<=K; i++)
        ans += dp[N][i];
    cout << ans << endl;
}