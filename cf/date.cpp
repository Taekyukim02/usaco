#include <iostream>
#include <algorithm>
#define MAX_N 300000ll
#define MOD 1000000007ll

using namespace std;

long long N, x[MAX_N];

long long expo(long long b, long long e) {
	if(e == 0)	return 1;
	if(e == 1)	return b;
	if(e%2)	return b*expo(b*b%MOD, e/2)%MOD;
	return expo(b*b%MOD, e/2);
}

int main() {
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> x[i];
	
	sort(x, x+N);

	long long sum=0;
	for(int i=0; i<N; i++)
		sum = (sum + (x[i] * ((i==0) ? 1 : expo(2, i))) % MOD) % MOD;
	
	for(int i=0; i<N; i++)
		sum = (sum - (x[i] * ((i==N-1) ? 1 : expo(2, N-1-i)))%MOD + MOD*3)%MOD;
	
	cout << sum << endl;
}
