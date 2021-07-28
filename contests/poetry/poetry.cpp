#include <iostream>
#include <fstream>
#include <algorithm>
#define MOD 1000000007ll
using namespace std;

int N, M, K;
int s[5005], c[5005];
char e[100005];

long long dp[5005];
long long numComb[5005];
long long cnt[26];

// fast expo
long long expo(long long b, long long e) {
    if(e == 0) return 1ll;
    if(e == 1) return b%MOD;
    if(e%2 == 1) return (b*expo((b*b)%MOD, (e-1)/2))%MOD;
    return expo((b*b)%MOD, e/2)%MOD;
}

int main() {
	ifstream fin ("poetry.in");
    fin >> N >> M >> K;
    for(int i=0; i<N; i++) {
        fin >> s[i] >> c[i];
    }
    for(int i=0; i<M; i++)
        fin >> e[i];
    
    // dp
    dp[0] = 1;
    for(int j=0; j<=K; j++)
		for(int i=0; i<N; i++)
			if(j-s[i] >= 0)
				dp[j] = (dp[j] + dp[j-s[i]])%MOD;
    
    // calculate numComb
    for(int i=0; i<N; i++)
        numComb[c[i]] = (numComb[c[i]] + dp[K-s[i]])%MOD;
    
    // count number of groups
    for(int i=0; i<M; i++)
        cnt[e[i]-'A']++;
    
    // calculate answer
    long long ans=1;    
    for(int i=0; i<26; i++) {
        long long curr=0;
        for(int j=1; j<=N; j++)
			if(numComb[j] > 0 && cnt[i] > 0) {
				curr = (curr+expo(numComb[j], cnt[i])) % MOD;
			}
		if(curr > 0) 
			ans = (ans*curr)%MOD;
    }
    
	/*
    for(int i=0; i<=K; i++)
        cout << dp[i] << " \n"[i==K];
    for(int i=0; i<N; i++)
        cout << numComb[i] << " \n"[i==N-1];
		*/
        

	ofstream fout ("poetry.out");
    fout << ans << endl;
}
