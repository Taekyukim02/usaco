#include <iostream>

using namespace std;

int N, A[1005], pre[1006];

int main() {
	cin >> N;
	pre[0] = 0;
	for(int i=0; i<N; i++) {
		cin >> A[i];
		pre[i+1] = pre[i] + A[i];
	}

	int ans = 0;
}
