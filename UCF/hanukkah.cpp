#include <iostream>

using namespace std;

int main() {
    int g; cin >> g;
    for(int gg=0; gg<g; gg++) {
        long long N, a, b;
        cin >> N >> a >> b;
        if(b < a) {
            long long t = a;
            a = b;
            b = t;
        }
        if(N % 2 == 0 && (b-a) % 2 == 1) {
            cout << "Graph #" << gg + 1 << ": Impossible" << endl;
        } else if(N % 2 == 0) {
            long long ret = (b-a)/2;
            ret = min(ret, N/2 - ret);
            cout << "Graph #"<<gg+1<<": " << ret << endl;
        } else {
            if((b-a) % 2 == 1)
                b += N;
            long long ret = (b-a)/2;
            ret = min(ret, N-ret);
            cout << "Graph #"<<gg+1<<": " << ret << endl;
        }
    }
}