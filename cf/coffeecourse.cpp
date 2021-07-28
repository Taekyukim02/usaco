#include <iostream>
#include <algorithm>

using namespace std;

long long N, M, A[200000];

long long solve(int num) {
	// N total things, put into rows of num length
	long long ans=0;

	for(int i=0; i<N; i++) {
		ans += (((A[i]-(i/num)) > 0) ? A[i] - (i/num) : 0);
	}
	
	return ans;
}

int main() {
	cin >> N >> M;
	for(int i=0; i<N; i++) {
		cin >> A[i];
		A[i] *= -1;
	}

	sort(A, A+N);
	for(int i=0; i<N; i++)
		A[i] *= -1;

	// check if possible
	if(solve(N) < M) {
		cout << -1 << endl;
		return 0;
	}

	// b search
	int low=1;
	int high=N;
	while(low < high) {
		int mid = (low+high)/2;
		long long value = solve(mid);
		if(value < M)
			low = mid+1;
		else
			high = mid;
	}

	cout << low << endl;
}
