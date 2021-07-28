#include <iostream>
#include <algorithm>

#define MOD 1000000007

using namespace std;

long long l, r;

long long sum(long long n) {
    if(n == 0)
        return 0;
    long long l = 0;
    long long h = 10000000000;
    while(l < h) {
        long long mid = (l+h)/2;
        if((mid)*(mid+1)/2 < n)
            l = mid;
        else
            h = mid;
    }

    long long ret = 0;
    if(l % 2 == 0) {
        long long num = (l/2+1)*(l/2)%MOD;
        ret += num*(num+1)%MOD;
        ret %= MOD;
        num = (l/2)*(l/2)%MOD;
        ret += num*num%MOD;
        ret %= MOD;
    } else {
        long long num = (l-1)/2*((l-1)/2+1)%MOD;
        ret += num*(num+1)%MOD;
        ret %= MOD;
        num = (l+1)/2*(l+1)/2%MOD;
        ret += num*num%MOD;
        ret %= MOD;
    }

    long long cur = (l)*(l-1)/2+2;

    for(long long i = l*(l+1)/2+1; i<=n; i++) {
        ret += cur;
        ret %= MOD;

        cur += 2;
    }

    return ret;
}

int main() {
    cin >> l >> r;
    long long a = sum(r);
    // long long b = sum(l-1);

    // cout << (a-b+MOD)%MOD << endl;

    return 0;
}