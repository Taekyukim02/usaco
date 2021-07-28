#include <iostream>
#include <algorithm>
#define MOD 998244353ll

using namespace std;

long long expo(long long b, long long e) {
	if(e == 0) return 1;
	if(e == 1) return b;
	if(e%2) return b*expo(b*b%MOD, (e-1)/2)%MOD;
	return expo(b*b%MOD, e/2);
}

long long bit1[200001];
long long bit2[200001];
long long get(long long bit[], long long x) {
	long long s = 0;
	for(; x>0; x-=x&(-x)) s += bit[x];
	return s;
}

long long N;
void add(long long bit[], long long x) {
	for(; x<=N; x+=x&(-x)) bit[x] += 1;
}

bool visited[200001];
int main() {
	cin >> N;
	long long arr[200000];
	long long numNeg = 0;
	long long T=0;
	for(long long i=0; i<N; i++) {
		cin >> arr[i];
		if(arr[i] == -1) {
			numNeg++;
		}
		else {
			T = (T + get(bit2, N-arr[i]+1))%MOD;
			add(bit2, N-arr[i]+1);
			visited[arr[i]] = true;
		}
	}
	// edge case
	if(numNeg == 0) {
		cout << T << endl;
		return 0;
	}

	for(long long i=1; i<=N; i++)
		if(!visited[i])
			add(bit1, i);

	long long P = 0;
	long long idNeg = 0;
	long long numR = numNeg;
	for(long long i=0; i<N; i++) {
		if(arr[i] == -1)
			numR--;
		else {
			long long numLess = get(bit1, arr[i]-1);
			P = (P + numR*numLess+(numNeg-numR)*(numNeg-numLess))%MOD;
		}
	}
	long long prod = numNeg*(numNeg-1)%MOD;
	long long ans = P;
	ans = ans*expo(numNeg, MOD-2)%MOD;
	ans = ((ans+T)%MOD+(prod*expo(2, MOD-3))%MOD)%MOD;
	cout << ans << endl;
	return 0;
}
