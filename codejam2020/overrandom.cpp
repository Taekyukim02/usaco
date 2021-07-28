#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<long long, long long> ii;

long long M[10005];
string R[10005];
ii cnt[26];
bool seenFront[26];

void solve() {
	long long U; cin >> U;
	for(int i=0; i<10000; i++)
		cin >> M[i] >> R[i];
	
	for(int i=0; i<26; i++) {
		cnt[i] = ii(0,i);
		seenFront[i] = false;
	}

	for(int i=0; i<10000; i++) {
		seenFront[R[i][0] - 'A'] = true;

		for(int j=0; j<R[i].length(); j++) {
			cnt[R[i][j] - 'A'].first++;
		}
	}

/*
	for(int i=0; i<26; i++) {
		cout << "i: " << cnt[i].first << " " << cnt[i].second << endl;
	}
	cout << endl;
	*/
	string ret = "";
	
	for(int i=0; i<26; i++)
		if(cnt[i].first > 0 && seenFront[i] == 0) {
			ret += char('A' + i);
			break;
		}

	sort(cnt, cnt+26);

	int del = 0;
	int indices[9];
	for(int i=0; i<9; i++) {
		if('A' + cnt[25-i-del].second == ret[0]) del++;
		ret += char('A' + cnt[25-i-del].second);
	}
	
	cout << ret << endl;
/*
	for(int i=0; i<26; i++)
		cout << i << ": " << cnt[i] << " " << seenFront[i] << endl;
		*/
}

int main() {
	int T; cin >> T;
	for(int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
}
