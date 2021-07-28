#include <iostream>
#include <string>
#define MOD 1000000007ll

using namespace std;

int dpUse[100005][52][52];
int dpNotUse[100005][52][52];
bool used[52];
int cnt[52];

// map for character to int (0-51)
int mp(char c) {
	if('a' <= c && c <= 'z')
		return c-'a';
	return c-'A'+26;
}

int main() {
	cin >> s;

	for(int i=0; i<s.length(); i++) {
		used[mp(s[i])] = true;
		cnt[mp(s[i])]++;
	}

	// find dpUse and dpNotUse
	for(int i=0; i<52; i++)
		for(int j=0; j<52; j++) {
			dpUse[0][i][j] = dpNotUse[0][i][j] = 1;

			// Use
			for(int l=0; l<52; l++) {
				for(int k=s.length(); k>=1; k--) {
					dpUse[k][i][j] = (dpUse[k][i][j] + dpUse
				}

			// NotUse
		}

	// take in queries
	int Q;
	cin >> Q;
	for(int i=0; i<Q; i++) {
		int x, y;
		cin >> x >> y;
		
		long long ans = 0;
		if(s.length()/2 - cnt(mp(s[x-1])) - cnt(mp(s[y-1])) >= 0)
			ans = dpNotUse[s.length()/2][mp(s[x-1])][mp(s[y-1])]
			* dpUse[s.length()/2 - cnt(mp(s[x-1])) - cnt(mp(s[y-1]))]
							[mp(s[x-1])][mp(s[y-1])];

		cout << ans % MOD << endl;
	}

	return 0;
}
