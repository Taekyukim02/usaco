#include <iostream>

using namespace std;

int N, a[20];
long long dp[1<<15];

int main() {
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> a[i];
	
	for(int i=0; i<(1<<N); i++)
		dp[i] = 987654321;

	for(int i=0; i<N; i++)
		dp[1<<i] = 0;
		
	for(long long i=1; i<(1<<N)-1; i++) {
		for(int j=0; j<N; j++) {
			if(((1<<j) & i) == 0) {
				long long n = ((1<<j) | i);
				long long prod = 1;
				for(int k=0; k<N; k++)
					if(((1<<k) & i) != 0 && k!=j)
						prod *= abs(a[k] - a[j]);
				if(dp[n] > dp[i] + prod)
					dp[n] = dp[i] + prod;
			}
		}
	}

	cout << dp[(1<<N)-1] << endl;
}
