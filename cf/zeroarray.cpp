//
// Created by Tae Kyu Kim on 2019-08-04.
//
#include <iostream>
#define MAX_N 100005

using namespace std;

int main() {
    long long N, tot, mx;
    tot = mx = 0;

    cin >> N;
    for(int i=0; i<N; i++) {
        long long a;
        cin >> a;
        tot += a;
        mx = max(mx, a);
    }

    if(tot % 2 == 0 && tot >= 2*mx)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
