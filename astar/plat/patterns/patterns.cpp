#include <iostream>
#include <map>
#define prime 31ll
#define MOD 1000000009ll

using namespace std;

int N, K;
long long hsh[20000];
long long p[20000];

long long powr(long long b, long long e) {
	if(e==0) return 1;
	if(e==1) return b;
	if(e%2) return b*powr(b*b%MOD, (e-1)/2)%MOD;
	return powr(b*b%MOD, e/2);
}

void prehsh() {
	hsh[0] = p[0];
	for(int i=1; i<N; i++)
		hsh[i] = (hsh[i-1] + (powr(prime,i)*p[i])%MOD)%MOD;
}

long long gethsh(int i, int j) {
	if(i==0)
		return hsh[j];
	return (hsh[j]-hsh[i-1]+MOD)%MOD * powr(prime, MOD-i-1)%MOD;
}

bool found(int len) {
	map <long long, int> mp;
	for(int i=0; i+len-1<N; i++) {
		long long h = gethsh(i, i+len-1);
		if(mp.find(h) != mp.end())
			mp[h]++;
		else
			mp[h] = 1;
	}
	
	int m = 0;
	for(auto it = mp.begin(); it != mp.end(); ++it)
		if(m < it->second)
			m = it->second;

	return (m >= K);
}

int main() {
	cin >> N >> K;
	for(int i=0; i<N; i++)
		cin >> p[i];
	
	prehsh();

	int l=1;
	int h=N;
	while(l<h) {
		int mid = (l+h+1)/2;
		if(found(mid))
			l = mid;
		else
			h = mid-1;
	}

	cout << l << endl;
	return 0;
}
