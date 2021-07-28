#include <iostream>
#include <cstdlib>
#include <random>
#include "Matrix.h"

#define BND 10000

using namespace std;

unsigned long long mypow(unsigned long long a, unsigned long long b, unsigned long long mod);
unsigned long long upLog(unsigned long long p, unsigned long long N);
bool isPrime(unsigned long long k);
unsigned long long mygcd(unsigned long long a, unsigned long long b);
Matrix<unsigned long long> matExp(Matrix<unsigned long long>, unsigned long long k, unsigned long long N);

mt19937_64 generator (rand());

// return factor of N using 2x2 matrix
unsigned long long matrixFactor(unsigned long long N) {
    Matrix <unsigned long long> c(2, 2);   // 2-dimensional matrix that is 2x2

    for(int i=0; i<50; i++) {
        cout << "tried " << i << " times " << endl;
        unsigned long long a, b;
        c.put(0, 0, 1);
        c.put(0, 1, a = generator() % (7654321));
        c.put(1, 0, b = generator() % (7654321));
        c.put(1, 1, (a*b+1) % N);

        for(unsigned long long p=2; p<BND; p++)
            if(isPrime(p)) {
                unsigned long long e = upLog(p, N);
                c = matExp(c, mypow(p, e, LONG_LONG_MAX), N);
                unsigned long long g = mygcd(N, 5*N + c.get(0,0) - c.get(1,1));
                if(g > 1 && g != N)
                    return g;
                cout << "after " << p << " " << e << endl;
                cout << c << endl;
            }
    }

    return -1;
}

int main() {
    unsigned long long N;
    cout << "Input number to factor ---> ";
    cin >> N;
    cout << endl;

    /*
    // test
    Matrix <unsigned long long> c(2, 2);   // 2-dimensional matrix that is 2x2

    for(int i=0; i<50; i++) {
        unsigned long long a, b;
        c.put(0, 0, 1);
        c.put(0, 1, a = generator() % (7654321));
        c.put(1, 0, b = generator() % (7654321));
        c.put(1, 1, (a * b + 1) % N);
    }

    cout << c << endl;

    return 0;
     */

    while(N > 1) {
        unsigned long long f = matrixFactor(N);
        if(f == -1) {
            cout << "couldn't factor " << N << endl;
            break;
        } else {
            cout << f << endl;
            N /= f;
        }
    }
}

//////////////////////////////
//      helper methods      //
//////////////////////////////

unsigned long long mypow(unsigned long long a, unsigned long long b, unsigned long long mod) {
    if(b == 0) return 1;
    if(b == 1) return a % mod;
    if(a % 2) return a*mypow(a*a % mod, b/2, mod) % mod;
    return mypow(a*a % mod, b/2, mod);
}

unsigned long long upLog(unsigned long long p, unsigned long long N) {
    unsigned long long ret = 0;
    while(N > 0) {
        N /= p;
        ret ++;
    }
    return ret;
}


bool isPrime(unsigned long long k) {
    for(unsigned long long i=2; i*i<=k; i++)
        if(k%i == 0)
            return false;

    return true;
}

unsigned long long mygcd(unsigned long long a, unsigned long long b) {
    if(a == 0) return b;
    return mygcd(b % a, a);
}

// get  c^k  where c is a matrix in Z/nZ
Matrix<unsigned long long> matExp(Matrix<unsigned long long> c, unsigned long long k, unsigned long long N) {
    Matrix<unsigned long long> res(2,2);
    res.put(0, 0, 1);     res.put(0, 1, 0);
    res.put(1, 0, 0);     res.put(1, 1, 1);

    while (k > 0) {
        // If y is odd, multiply x with result
        if (k & 1)
            res *= c;

        // k must be even now
        k = k >> 1; // k = k/2
        c *= c; // Change c to c^2
        c.put(0,0, c.get(0,0) % N);
        c.put(1,0, c.get(1,0) % N);
        c.put(0,1, c.get(0,1) % N);
        c.put(1,1, c.get(1,1) % N);

        res.put(0,0, c.get(0,0) % N);
        res.put(1,0, c.get(1,0) % N);
        c.put(0,1, c.get(0,1) % N);
        c.put(1,1, c.get(1,1) % N);
    }
    return res;
}
