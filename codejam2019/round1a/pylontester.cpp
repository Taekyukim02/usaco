#include <iostream>

using namespace std;

int main() {
    int N, a, b, c, d;
    cin >> N;
    cin >> a >> b;
    for(int i=1; i<=N; i++) {
        cin >> c >> d;

        if(a == c || b == d || a-b == c-d || a+b == c+d)
            cout << "Fail on " << i << endl;

        a = c;
        b = d;
    }
}