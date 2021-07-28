#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <algorithm>

using namespace std;

string str;
int N, K;

int main() {
	cin >> N >> K;
	cin >> str;

	// check if # of black <= K; then get all white
	long long cnt_black = 0;
	for(int i=0; i<N; i++) {
		if(str[i] == 'B')
			cnt_black++;
	}
	if(cnt_black <= K) {
		cout << N - K << endl;
		return 0;
	}

	// otherwise, do sliding window
	int lft = 0;
	int rht = N;
	cnt_black = 0;
	while(cnt_black <= K) {
		if(str[lft] == 'B')
			cnt_black++;
		lft++;
	}
	while(str[rht-1] == 'W')
		rht--;

	// iterate
	int bestans = (N-1 - rht) + (lft - K);
//	cout << lft << " " << rht << " " << bestans << endl;
	while(lft > 0) {
		lft --;
		if(str[lft] == 'B') {
			rht --;
			while(str[rht] == 'W')
				rht--;
		}
		int currans = (N-1 - rht) + (lft - K);
		if(currans > bestans)
			bestans = currans;
//		cout << lft << " " << rht << " " << bestans << endl;
	}
	cout << bestans << endl;
}
