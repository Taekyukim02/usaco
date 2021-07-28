#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <map>
#define MAX_N 500010

using namespace std;

long long psum[MAX_N];
long long a[MAX_N];

int main() {
	long long N; cin >> N;
	long long tot = 0;
	for(long long i=0; i<N; i++) {
		cin >> a[i];
		tot += a[i];
	}

	long long avg = tot/N;
	for(long long i=0; i<=N; i++) {
		a[i] -= avg;
		psum[i+1] = psum[i] + a[i];
	}

	// dictionary counts of psum[] for indices >= 1
	map <long long, long long> mymap;
	for(long long i=1; i<=N; i++) {
		if(mymap.find(psum[i]) == mymap.end())
			mymap[psum[i]] = 1;
		else
			mymap[psum[i]]++;
	}

	long long mybest = -100;
	for(auto it = mymap.begin(); it != mymap.end(); it++) {
		if(mybest < it->second)
			mybest = it->second;
	}
	cout << N-mybest << endl;
}
