#include <iostream>

using namespace std;

int main() {
	int N, x, y;
	cin >> N >> x >> y;
	if(x > y) {
		cout << N << endl;
		return 0;
	}

	int cnt = 0;
	for(int i=0; i<N; i++) {
		int a;
		cin >> a;
		if(a <= x)
			cnt++;
	}
	cout << (cnt+1)/2 << endl;
}
