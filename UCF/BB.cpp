#include <iostream>

#define MAX_N 200000

using namespace std;

double a[MAX_N], b[MAX_N];

int main() {
    int N, d;
    double p;
    cin >> N >> d >> p;
    for(int i=0; i<MAX_N; i++) {
        a[i] = b[i] = 0;
    }

    for(int i=0; i<N; i++) {
        a[i] += p;
        a[i+d] += a[i] * p;
        b[i+d] += a[i] * (1-p);
        a[i+1] += b[i] * p;
        b[i+1] += b[i] * (1-p);
    }
    /*
     * for(int i=1; i<N; i++) {
        b[i] = b[i-1] * (1-p);
        if(i >= d)
            b[i] += a[i-d] * (1-p);
        a[i] = p + p*b[i-1];
        if(i >= d)
            a[i] += p*a[i-d];
        cout << a[i] << " " << b[i] << endl;
    }
     */
    cout << 2*a[N-1] + 2*b[N-1] << endl;
}