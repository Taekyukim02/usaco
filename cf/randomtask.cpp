#include <iostream>

using namespace std;

long long M, K;
long long dp[70][70];

// count # of binary strings of length m with exactly k 1's
long long numValid(long long m, long long k) {
	if(m < 0 || k < 0)
		return 0;
	if(m < k)
		return 0;
	if(m == k)
		return dp[m][k] = 1;
	if(dp[m][k])
		return dp[m][k];
	
	return dp[m][k] = (numValid(m-1, k) + numValid(m-1, k-1));
}

int main() {
	cin >> M >> K;

	// binary search on answer
	long long l = 0, r=(1ll<<60);
	int len = 61;	// length of mid
	while(l < r) {
		cout << l << " " << r << endl;
		long long mid = (l+r)/2;
		// # of valid b-strings when n=mid
		long long test = numValid(len-1, K-1);
		cout << "test " << test << endl;
		cout << "len, K" << len << " " << K << endl;
		if(test == M) {
			cout << mid << endl;
			return 0;
		}
		if(test < M) {
			l = mid;
			K--;
		} else {
			r = mid;
		}

		len--;
	}

	return 0;
}
