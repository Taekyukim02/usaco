//
// Created by Tae Kyu Kim on 2019-08-04.
//
#include <iostream>
#include <algorithm>

#define MAX_N 200005

using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;

    long long a[MAX_N];
    for (int i = 0; i < N; i++)
        cin >> a[i];

    sort(a, a+N);

    for(int i=0; i<=(N-1)/2; i++) {
        long long curr = a[(N-1)/2 + i];
        long long nxt = 100000000000;
        if(i != (N-1)/2) nxt = a[(N-1)/2 + i + 1];

        long long mxinc = nxt - curr;
        long long mn = min(mxinc, K/(i+1));
        a[(N-1)/2] += mn;
        K -= mn * (i+1);
    }

    cout << a[(N-1)/2] << endl;
}