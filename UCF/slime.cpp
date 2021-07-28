#include <iostream>
#include <queue>

using namespace std;

queue <int> odd[17];

int log2(int a) {
    int r = 0;
    while(a % 2 == 0) {
        a /= 2;
        r++;
    }
    return r;
}
int main() {
    int T; cin >> T;
    for(int t=1; t<=T; t++) {
        int h;  cin >> h;
        long long att = h;
        long long tot = 0;
        for(int i=0; i<17; i++)
            odd[i] = queue<int>();

        odd[log2(h)].push(h);

        while(att > 0) {
            int n = -1;
            int a =0;
            while(n == -1) {
                if (!odd[a].empty()) {
                    n = odd[a].front();
                    odd[a].pop();
                }
                a++;
            }
            if(n/2 > 0) {
                int b = log2(n/2);
                odd[b].push(n/2);
                odd[b].push(n/2);
            }
            att = att-n + (n/2)*2;
            tot += att;
        }

        cout << "Fight #"<<t<<": " << tot << endl;
    }
}