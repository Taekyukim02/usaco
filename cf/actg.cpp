#include <iostream>

using namespace std;

int dist(char a, char b) {
    return min(
            min(b-a >= 0 ? b-a : 987654321,
               a-b >= 0 ? a-b : 987654321),
            min(26-b+a >= 0 ? 26-b+a : 987654321,
               26-a+b >= 0 ? 26-a+b : 987654321));
}

int main() {
    int N;
    string s;
    cin >> N >> s;
    int mymin = 987654321;
    for(int i=0; i<N-3; i++) {
        int newDist = dist(s[i], 'A')
                    + dist(s[i+1], 'C')
                    + dist(s[i+2], 'T')
                    + dist(s[i+3], 'G');

        if(newDist < mymin)
            mymin = newDist;
    }
    cout << mymin << endl;
}