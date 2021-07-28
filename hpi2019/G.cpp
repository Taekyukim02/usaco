#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int DP[100005];
int N, M;

int main() {
	cin >> N >> M;
	
	for (int i = 1; i < 100005; i ++)
		DP[i] = -1000000000;

	int x, y;
	int ans = 0;

	for (int i = 0; i < N; i ++) {
		cin >> y >> x;	
		
		for (int i = M - x; i >= 0; i --) {	
			DP[i + x] = max(DP[i + x], DP[i] + y);
			ans = max(ans, DP[i + x]);
		}
	}

	cout << ans << endl;
	return (0);	
}

