#include <iostream>

using namespace std;

long long a[1000];

long long pw(int e, int b) {
    if(b == 0) return 1;
    return e * pw(e, b-1);
}
int main () {
    int N;
    cin >> N;
    while(N--) {
        int i;
        cin >> i;
        for(int j=0; j<=i; j++)
            cin >> a[j];
        int d, k;
        cin >> d >> k;
        bool f = true;
        for(int n=1; n<10000000 && f; n++) {
            k -= n*d;
            if(k <= 0) {
                long long ans = 0;
                for (int j = 0; j <= i; j++) {
                    ans += a[j] * pw(n, j);
                }
                cout << ans << endl;
                f = false;
            }
        }
    }
}