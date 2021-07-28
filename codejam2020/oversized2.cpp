#include <iostream>
#include <algorithm>

using namespace std;

long long A[10005];

long long mymin(long long a, long long b) {
	if(a < b) return a;
	return b;
}

void solve() {
	long long N, D; cin >> N >> D;
	for(int i=0; i<N; i++)
		cin >> A[i];
	
	sort(A, A+N);
	
	bool doubled = false;
	bool extra = false;
	bool tripled = false;
	for(int i=1; i<N; i++) {
		if(A[i] == A[i-1]) {
			doubled = true;
			if(i < N-1)
				extra = true;
			if(i < N-1 && A[i] == A[i+1])
				tripled = true;
		}
	}

	bool tripling = false;
	for(int i=0; i<N; i++)
		for(int j=1; j<N; j++) {
			if(A[i] == A[j]) continue;
			if(A[i] * 2 == A[j]) tripling = true;
		}

	if(tripled)
		cout << "0" << endl;
	else if(tripling && D == 3)
		cout << "1" << endl;
	else if(doubled && D == 2)
		cout << "0" << endl;
	else if(doubled && D == 3) {
		if(extra)
			cout << "1" << endl;
		else
			cout << "2" << endl;
	}
	else if(D == 2)
		cout << "1" << endl;
	else if(D == 3)
		cout << "2" << endl;
}

int main() {
	int T; cin >> T;
	for(int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
}
