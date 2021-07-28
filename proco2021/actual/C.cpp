#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <map>
#define MAX_N 100010

using namespace std;

map <long long, long long> cnt;
long long players[MAX_N];
long long misses[MAX_N];

int main()
{
	long long S, N; 
	cin >> S >> N;
	for(int i=0; i<N; i++) {
		int x; cin >> x;
		if(cnt.find(x) == cnt.end())
			cnt[x] = 1;
		else
			cnt[x]++;
	}
	
	long long i=1;
	misses[0] = 0;
	for(auto it = cnt.begin(); it != cnt.end(); it++, i++) {
		players[i] = it->first;
		misses[i] = it->second + misses[i-1];
	}
	int num = i;
/*
	for(int i=0; i<num; i++) {
		cout << misses[i] << " ";
	}
		cout << endl;
		*/
	
	long long Q; cin >> Q;
	for(i=0; i<Q; i++) {
		long long x; cin >> x;
		long long low = 0;
		long long high = num-1;
		
		while(low < high) {
			long long mid = (low + high + 1)/2;
			if(misses[mid] < x)
				low = mid;
			else if(misses[mid] > x)
				high = mid-1;
			else
				high = low = mid;
		}

		if(low == num-1)
			cout << S << endl;
		else
			cout << players[low+1]-1 << endl;
	}
}
