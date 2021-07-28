#include <iostream>

#define MAX_N 1e5

using namespace std;

int N;
string p[MAX_N+5];
long long dp[MAX_N+5][26];

int main() {
	// read input
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> p[i];

	// base case

	// 
	
	// print output
	long long mx = -1;
	for(int i=0; i<26; i++) {
		mx = mymax(mx, dp[N-1][i]);
	}
	cout << mx << endl;
}
