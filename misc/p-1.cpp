#include <iostream>
#include <cstdlib>

#define BND 10000

using namespace std;

long long mypow(long long a, long long b, long long mod) {
    if(b == 0) return 1;
    if(b == 1) return a % mod;
    if(a % 2) return a*mypow(a*a % mod, b/2, mod) % mod;
    return mypow(a*a % mod, b/2, mod);
}

long long upLog(long long p, long long N) {
    long long ret = 0;
    while(N > 0) {
        N /= p;
        ret ++;
    }
    return ret;
}


bool isPrime(long long k) {
    for(int i=2; i*i<=k; i++)
        if(k%i == 0)
            return false;

    return true;
}

long long mygcd(long long a, long long b) {
    if(a == 0) return b;
    return mygcd(b % a, a);
}

// returns a factor of N using pollard's p-1 algorithm
long long pollard(long long N) {
    if(N <= 0) return 1;

    while(true) {
        long long a = rand() % N;
        long long A = a;
        for(int i=2; i<BND; i++) {
            if(isPrime(i)) {
                long long e = upLog(i, N);
                for(int j=0; j<e; j++)
                    A = mypow(A, i, N);
                long long g = mygcd(N, N+A-a);
                if(g > 1)
                    return g;
            }
        }
    }
}

int main() {
    long long N = 377681131;
    while(N > 1) {
        long long f = pollard(N);
        cout << f << endl;
        N /= f;
    }
    cout << "done" << endl;
}