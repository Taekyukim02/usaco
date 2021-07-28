#include <iostream>
#include <fstream>
#include <algorithm>

#define MAX_N 305

using namespace std;

int N, K;
long long M;
int a[MAX_N];
long long answer[MAX_N];
long long depth[MAX_N];

void find_depth(int l, int r, int d) {
    if(l > r) return;
    if(l == r) {
        depth[l] = d;
        return;
    }

    int x = l;
    for(int i=l; i<=r; i++) {
        if(a[i] < a[x]) x = i;
    }

    depth[x] = d;
    find_depth(l, x-1, d+1);
    find_depth(x+1, r, d+1);
}

int main() {
    ifstream fin ("treedepth.in");
    fin >> N >> K >> M;
    fin.close();

    for(int i=0; i<N; i++)
        a[i] = i+1;

    do {
        int k=0;
        for(int i=0; i<N-1; i++)
            for(int j=i+1; j<N; j++)
                if(a[i] > a[j]) k++;

        if(k == K) {
            find_depth(0, N-1, 1);
            for(int i=0; i<N; i++)
                answer[i] = (answer[i] + depth[i]) % M;
        }
    } while (next_permutation(a, a+N));

    ofstream fout ("treedepth.out");
    for(int i=0; i<N; i++)
        fout << answer[i] << " \n"[i==N-1];
    fout.close();

    return 0;
}