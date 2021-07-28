#include <iostream>

#define MAX_N 1005

using namespace std;

int T, N, t, ans;
string str[MAX_N];
int nxt[50*MAX_N][26];
int val[50*MAX_N][26];

void add(string s) {
    int i = s.length()-1;
    int currIdx = 0;
    while(i >= 0) {
        if(nxt[currIdx][s[i]-'A'] != 0)
            currIdx = nxt[currIdx][s[i]-'A'];
        else {
            nxt[currIdx][s[i] - 'A'] = ++t;
            currIdx = t;
        }
        i--;
    }
    val[currIdx][s[0] - 'A']++;
}

int search(int n) {
    int curr = 0;
    for(int i=0; i<26; i++) {
        if(nxt[n][i] != 0)
            curr += search(nxt[n][i]);
        curr += val[n][i];
    }
    if(curr >= 2 && n != 0) {
        curr -= 2;
        ans += 2;
    }
    return curr;
}

int main() {
    cin >> T;
    for(int i=1; i<=T; i++) {
        cin >> N;
        for(int j=0; j<=50*N; j++)
            for(int k=0; k<26; k++)
                nxt[j][k] = val[j][k] = 0;

        ans = t = 0;
        for(int j=0; j<N; j++) {
            cin >> str[j];
            add(str[j]);
        }

        search(0);

        cout << "Case #";
        cout << i;
        cout << ": ";
        cout << ans << endl;
    }
}