#include <iostream>

using namespace std;

long long sx[100], sy[100];

void solve() {
	string ans;
	int t;
	for(t=0; t<49; t++) {
		cout << sx[t] << " " << sy[t] << endl << flush;
		cin >> ans;
		if(ans == "CENTER")
			return;
		if(ans == "HIT")
			break;
		if(ans == "WRONG")
			exit(0);
	}
	if(t == 50) return;		// bad
	
	// left
	long long l = -1000000000;
	long long r = sx[t];
	while(l < r) {
		long long mid = (l+r)/2;
		cout << mid << " " << sy[t] << endl << flush;
		cin >> ans;
		if(ans == "CENTER")
			return;
		if(ans == "HIT")
			r = mid;
		if(ans == "MISS")
			l = mid+1;
		if(ans == "WRONG")
			exit(0);
	}
	long long x1 = l;

	// right
	l = sx[t];
	r = 1000000000;
	while(l < r) {
		long long mid = (l+r+1)/2;
		cout << mid << " " << sy[t] << endl << flush;
		cin >> ans;
		if(ans == "CENTER")
			return;
		if(ans == "HIT")
			l = mid;
		if(ans == "MISS")
			r = mid-1;
		if(ans == "WRONG")
			exit(0);
	}
	long long x2 = l;

	// up
	l = sy[t];
	r = 1000000000;
	while(l < r) {
		long long mid = (l+r+1)/2;
		cout << sx[t] << " " << mid << endl << flush;
		cin >> ans;
		if(ans == "CENTER")
			return;
		if(ans == "HIT")
			l = mid;
		if(ans == "MISS")
			r = mid-1;
		if(ans == "WRONG")
			exit(0);
	}
	long long y1 = l;

	// down
	l = -1000000000;
	r = sy[t];
	while(l < r) {
		long long mid = (l+r)/2;
		cout << sx[t] << " " << mid << endl << flush;
		cin >> ans;
		if(ans == "CENTER")
			return;
		if(ans == "HIT")
			r = mid;
		if(ans == "MISS")
			l = mid+1;
		if(ans == "WRONG")
			exit(0);
	}
	long long y2 = l;

	cout << (x1+x2)/2 << " " << (y1+y2)/2 << endl << flush;
	cin >> ans;

	if(ans != "CENTER")
		exit(0);
}

int main() {
	int T; cin >> T;
	int A, B; cin >> A >> B;
	
	int k=0;
	for(int i=-3; i<=3; i++)
		for(int j=-3; j<=3; j++) {
			sx[k] = i*250000000;
			sy[k] = j*250000000;
			k++;
		}
	
	for(int t=1; t<=T; t++) {
		solve();
	}
}
