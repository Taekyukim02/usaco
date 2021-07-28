#include <iostream>

using namespace std;

int main() {
    int S; cin >> S;
    for(int s=1; s<=S; s++) {
        bool j = false;
        bool k = false;

        int N, K; cin >> N >> K;
        int jx = 0, kx = 0;
        for(int i=0; i<N; i++) {
            string s;
            int x;
            cin >> s >> x;
            if(s == "Kelly") kx = x;
            if(s == "Jim")  jx = x;
            if(kx > jx + K) j = true;
            if(jx > kx + K) k = true;
        }

        if(j && k) cout << "Their friendship is doomed" << endl;
        if(j && !k) cout << "Jim hates Kelly" << endl;
        if(!j && k) cout << "Kelly hates Jim" << endl;
        if(!j && !k) cout << "Everything is good" << endl;
    }
}