#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>

#define MAX_N 100009
#define MOD 998244353ll
#define Default -1

using namespace std;

void fastscan(long long &number)
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

long long N, K;
long long A[MAX_N][2];
long long dp[MAX_N][2];
long long s[MAX_N], d[MAX_N];

long long diff(int len);
long long same(int len) {
    if(s[len] != Default)
        return s[len];

    if(len == 1) {
        return K;
    }
    if(len == 2) {
        return 0;
    }
    if(len == 3) {
        return K*(K-1)%MOD;
    }

    s[len] = diff(len-1)%MOD;
    return s[len];
}

long long diff(int len) {
    if(d[len] != Default)
        return d[len];

    if(len == 1) {
        return 0;
    }
    if(len == 2) {
        return K*(K-1)%MOD;
    }
    if(len == 3) {
        return K*(K-1)%MOD*(K-2)%MOD;
    }

    d[len] = ((K-2) * diff(len-1)%MOD + (K-1)*same(len-1)%MOD)%MOD;
    return d[len];
}

long long expo(long long b, long long e) {
    if(e == 0) return 1;
    if(e == 1) return b%MOD;
    if(e%2 == 1) return b*expo(b*b%MOD, (e-1)/2)%MOD;
    if(e%2 == 0) return expo(b*b%MOD, e/2)%MOD;
}

int main() {
    fastscan(N);
    fastscan(K);
    for(int i=0; i<N; i++)
        fastscan(A[i/2][i%2]);

    for(int i=0; i<MAX_N; i++)
        s[i] = d[i] = Default;

    long long ans = 1;
    for(int m=0; m < 2; m++) {
        int prev = -2;
        int cnt=0;
        for(int i=0; 2*i + m < N; i++) {
            if(A[i][m] == -1) {
                cnt++;
            } else if(prev == A[i][m] && cnt == 0) {
                ans = 0;
            } else if(prev != A[i][m] && cnt == 0) {
                prev = A[i][m];
            } else if(prev == A[i][m] && cnt != 0) {
                ans = ans * same(cnt+2) %MOD * expo(K, MOD-2) %MOD;

                cnt = 0;
                prev = A[i][m];
            } else if(prev != A[i][m] && prev != -2 && cnt != 0){
                ans = ans * diff(cnt+2) %MOD * expo(K*(K-1)%MOD, MOD-2) %MOD;

                cnt = 0;
                prev = A[i][m];
            } else if(prev != A[i][m] && prev == -2 && cnt != 0){
                ans = ans*((same(cnt)+diff(cnt))%MOD)%MOD*(K-1)%MOD*expo(K, MOD-2)%MOD;

                cnt = 0;
                prev = A[i][m];
            }

            if(ans == 0)
                break;
        }

        if(prev == -2 && cnt > 0) {
            ans = ans*K%MOD*expo(K-1, cnt-1)%MOD;
        } else if(prev != -2 && cnt > 0) {
            ans = ans*expo(K-1, cnt)%MOD;
        }

    }

    cout << ans << endl;
}