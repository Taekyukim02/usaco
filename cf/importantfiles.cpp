//
// Created by Tae Kyu Kim on 2019-08-04.
//
#include <iostream>
#define MAX_N 1005

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    string str[MAX_N];
    int val[MAX_N];

    for(int i=0; i<N; i++)
        cin >> str[i];
    for(int i=0; i<M; i++)
        cin >> val[i];

    long long total = 0;
    for(int i=0; i<M; i++) {
        int cnt[5];
        for(int j=0; j<5; j++)
            cnt[j] = 0;

        for(int j=0; j<N; j++) {
            cnt[str[j][i] - 'A']++;
        }
        total += val[i] * max(cnt[0], max(cnt[1], max(cnt[2], max(cnt[3], cnt[4]))));
    }

    cout << total << endl;
}
