#include <iostream>

using namespace std;

int N, K;

int main() {
	cin >> N >> K;

	cout << 2+3+2*(N-2) + (N-1) + min(N-K, K-1) << endl;
}
