#include <iostream>

using namespace std;

int main() {
    int T;  cin >> T;
    for(int t=1; t<=T; t++) {
        long long g, d; cin >> g >> d;
        long long l = 10;
        long long r = 1876543219876543211;
        while(l < r) {
            long long mid = (l+r)/2;
            long long res = 0;
            bool high = false;
            for(long long i=100000000000000; i>=1; i /= 10) {
                res *= mid;
                res += (g / i) % 10;
                if (res > d) {
                    high = true;
                    break;
                }
            }
            if(res > d) high = true;
            if(high) r = mid-1;
            if(!high && res < d) l = mid+1;
            if(!high && res == d) {
                l = mid;
                break;
            }
        }

        cout << "Hotel Visit #"<<t<<": Base " << l << endl;
    }
}
