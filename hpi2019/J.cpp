#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

long long DP[MAX_N], ar[MAX_N];
long long N;

int main() {
	cin >> N;

	for (int i = 0; i < N; i ++)
		cin >> ar[i];
	
	long long ans = 0ll;

	DP[0] = max(0ll, ar[0]);
	DP[1] = max(0ll, max(ar[0], ar[1]));

	ans = max(DP[0], DP[1]);

	for (int i = 2; i < N; i ++) {
		DP[i] = max((long long)(DP[i - 1]), (long long)(DP[i - 2] + ar[i]));	
		ans = max(ans, DP[i]);
	}
	
	cout << ans << endl;
	return (0);
}

