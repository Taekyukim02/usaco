#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <queue>

#define MAX_N 100005
#define MAX_K 105
#define MOD 998244353ll

using namespace std;

typedef pair <long long, int> ii;

void fastscan(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;

    number = 0;

    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;

        // extract the next character from the buffer
        c = getchar();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}

int N, K, len;
int arr[MAX_N];
long long dp[MAX_N][MAX_K];
long long sum[MAX_N];
long long sumDp[MAX_K];
long long myleft[MAX_K];

int main() {
    // read input
    fastscan(N);
    fastscan(K);
    fastscan(len);
    for(int i=1; i<=N; i++)
        fastscan(arr[i]);

    // dp
    sum[0] = 1;
    for(int j=1; j<=K; j++)
        myleft[j] = 1;

    for(int i=1; i<len; i++) {
        if(arr[i] == -1) {
            sum[i] = sum[i-1] * K % MOD;
            for(int j=1; j<=K; j++) {
                dp[i][j] = sum[i - 1];
                sumDp[j] = (sumDp[j] + sum[i] - dp[i][j] + MOD) % MOD;
            }
        } else {
            dp[i][arr[i]] = sum[i-1];
            sum[i] = sum[i-1];
            for(int j=1; j<=K; j++) {
                if(j != arr[i]) {
                    myleft[j] = i;
                    sumDp[j] = sum[i];
                }
            }
        }

    }
    for(int i=len; i<=N; i++) {
        if(arr[i] == -1) {
            for(int j=1; j<=K; j++) {
                while(i - myleft[j] >= len) {
                    sumDp[j] = (sumDp[j] - (sum[myleft[j]] - dp[myleft[j]][j]) + MOD) % MOD;
                    myleft[j]++;
                }
                dp[i][j] = sumDp[j];
                sum[i] = (sum[i] + dp[i][j]) % MOD;
            }
            for(int j=1; j<=K; j++) {
                sumDp[j] = (sumDp[j] + sum[i] - dp[i][j] + MOD) % MOD;
            }
        } else {
            int j = arr[i];
            while(i - myleft[j] >= len) {
                sumDp[j] = (sumDp[j] - (sum[myleft[j]] - dp[myleft[j]][j]) + MOD) % MOD;
                myleft[j]++;
            }
            dp[i][arr[i]] = sum[i] = sumDp[arr[i]];

            for(j=1; j<=K; j++) {
                if(j != arr[i]) {
                    myleft[j] = i;
                    sumDp[j] = sum[i];
                }
            }
        }
    }
/*
    for(int i=1; i<=K; i++) {
        for(int j=0; j<=N; j++)
            cout << dp[j][i] << " \n"[j==N];
    }
    */
    // print answer
    cout << sum[N] << endl;

    return 0;
}