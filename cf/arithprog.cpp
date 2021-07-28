#include <iostream>

using namespace std;

int N, T=60;
bool seen[1000001];

long long gcd(long long a, long long b) {
	if(a == 0 || b == 0)
		return a+b;
	if(a >= b)
		return gcd(a%b, b);
	return gcd(b%a, a);
}

int main() {
	cin >> N;

	// find largest element using query 2
	long long l=0;
	long long h=1000000000;
	long long mid;
	long long res;
	while(l < h) {
		mid = (l+h)/2;
		T--;
		cout << "> " << mid << endl << flush;
		cin >> res;

		if(res == 1)
			l = mid+1;
		else
			h = mid;
	}

	// find random elements and get gcd of differences
	long long check=rand()%N*rand()%N+1;
	long long diff=0;
	int numChecked = 0;
	while(T > 0 && numChecked < N) {
		T--;
		numChecked++;
		while(seen[check])
			check = rand()%N*rand()%N+1;
		cout << "? " << check << endl << flush;
		cin >> res;
		seen[check] = true;

		diff = gcd(diff, h-res);
	}

	cout << "! " << h-diff*(N-1) << " " << diff << endl;
}
