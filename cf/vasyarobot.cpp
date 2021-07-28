#include <iostream>

#define MAX_N 200000
#define f first
#define s second

using namespace std;

typedef pair <long long, long long> ii;

long long N, x, y;
string str;
ii pre[MAX_N+5];

bool poss(int len) {
	for(int i=len; i<=N; i++) {
		long long nX, nY;
		nX = pre[N].f - pre[i].f + pre[i-len].f;
		nY = pre[N].s - pre[i].s + pre[i-len].s;
		
		if(len >= abs(x-nX) + abs(y-nY))
			return true;
	}

	return false;
}

int main() {
	// read input
	cin >> N >> str >> x >> y;

	// check if possible
	if(N < abs(x) + abs(y) || (N % 2 != (abs(x)+abs(y)) % 2)) {
		cout << -1 << endl;
		return 0;
	}

	// calculate prefix sums
	pre[0] = ii(0, 0);
	for(int i=0; i<N; i++) {
		if(str[i] == 'U')
			pre[i+1] = ii(pre[i].f + 0, pre[i].s + 1);
		if(str[i] == 'D')
			pre[i+1] = ii(pre[i].f + 0, pre[i].s - 1);
		if(str[i] == 'R')
			pre[i+1] = ii(pre[i].f + 1, pre[i].s + 0);
		if(str[i] == 'L')
			pre[i+1] = ii(pre[i].f - 1, pre[i].s + 0);
	}

	// binary search
	int l=0;
	int h=N;
	while(l < h) {
		int mid = (l+h)/2;
		if(poss(mid)) {
			h = mid;
		} else {
			l = mid+1;
		}
	}

	// output answer
	cout << l << endl;

	return 0;
}
