#include <iostream>

using namespace std;

long long N, K;

int main() {
	cin >> N >> K;

	if(N > K*(K-1)) {
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	long long delta = 1;
	long long first = 1;
	for(int i=0; i<N; i++) {
		cout << first << " " << (first+delta-1)%K + 1 << endl;

		first++;
		if(first > K) {
			first = 1;
			delta++;
		}
	}
}
