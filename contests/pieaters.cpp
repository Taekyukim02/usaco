#include <iostream>
#include <fstream>

#define MAX_M 22
#define MAX_N 55

using namespace std;

long long N, M,
dp[1<<MAX_M],
w[MAX_M], l[MAX_M], r[MAX_M];
bool possible[1<<MAX_M];

int main() {
    ifstream fin ("pieaters.in");
    fin >> N >> M;
    for(int i=0; i<M; i++) {
        fin >> w[i] >> l[i] >> r[i];
    }
    fin.close();

    long long best = 0;
    possible[0] = true;
    for(int i=0; i<(1<<M); i++) {
        if(!possible[i]) continue;

        bool eaten[MAX_N];
        for(int j=0; j<MAX_N; j++)
            eaten[j] = false;

        for(int j=0; j<M; j++)
            if((i & (1<<j)) > 0) // used
                for(long long k=l[j]; k<=r[j]; k++)
                    eaten[k] = true;

        for(int j=0; j<M; j++)
            if((i & (1<<j)) == 0) { // unused
                bool allEaten = false;
                for(long long k=l[j]; k<=r[j]; k++)
                    allEaten &= eaten[k];
                if(!allEaten) {
                    dp[i | (1<<j)] = (dp[i | (1<<j)] < dp[i] + w[j])
                                        ? dp[i] + w[j] : dp[i | (1<<j)];
                    possible[i | (1<<j)] = true;
                }
            }
    }

    for(int i=0; i<(1<<M); i++)
        if(possible[i] && best < dp[i])
            best = dp[i];

    ofstream fout ("pieaters.out");
//    for(int i=0; i<(1<<M); i++)
//        cout << i << " " << dp[i] << endl;
    fout << best << endl;
    fout.close();
}