#include <iostream>
#include <map>
#include <set>

#define MAX_N 100000

using namespace std;

int main()
{
	int N, K; 
	cin >> N >> K;

	int id[MAX_N];
	for(int i=0; i<N; i++)
		cin >> id[i];

	long long MOD = (1<<K)-1;

	long long pre[MAX_N];		// prefix sum of first i elements of id[]
	map <long long, set<int> > mp;
	pre[0] = 0;
	mp[pre[0]].insert(0);
	for(int i=1; i<=N; i++) {
		pre[i] = (pre[i-1] + id[i-1]) % MOD;
		mp[pre[i]].insert(i);
	}

	int maxLen = 0;
	for(auto it = mp.begin(); it != mp.end(); ++it) {
		set <int> st = it->second;
		int l = *st.begin();
		int r = *(--st.end());
		if(l != r) {
			maxLen = max(maxLen, r-l);
		}
	}

	cout << maxLen << endl;
	return 0;	
}
