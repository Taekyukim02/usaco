#include <iostream>
#include <algorithm>

#define MAX_N 100005

using namespace std;

string str[MAX_N];

int main() {
    int T; cin >> T;
    for(int t=1; t<=T; t++) {
        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> str[i];
        sort(str, str + N,
             [](const string &s1, const string &s2) {
                 int a, b;
                 for (int i = 0; i < 26; i++) {
                     a = b = 0;
                     for (int j = 0; j < s1.length(); j++)
                         if (s1[j] == 'a' + i)
                             a++;
                     for (int j = 0; j < s2.length(); j++)
                         if (s2[j] == 'a' + i)
                             b++;
                     if (a > b) return true;
                     if (a < b) return false;
                 }
                 return (s1.compare(s2) == 0);
             });
        cout << "Dictionary #" << t << ":" << endl;
        for (int i = 0; i < N; i++)
            cout << str[i] << endl;
        cout << endl;
    }
}