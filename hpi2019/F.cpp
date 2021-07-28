#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int use[500005];
int N, M;

int main() {
	cin >> N >> M;
	
	int x, y;
	for (int i = 0; i < N; i ++) {
		cin >> x;
		use[x] = true;
	}
	
	long long sum = 0ll;

	for (int i = 0; i < M; i ++) {
		cin >> x >> y;
		if (use[x])
			sum += y;
	}

	cout << sum << endl;
	return (0);	
}
