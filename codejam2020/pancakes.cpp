#include <iostream>

using namespace std;

long long myabs(long long a) {
	if(a < 0) return -a;
	return a;
}

long long mymin(long long a, long long b) {
	if(a < b) return a;
	return b;
}

int main() {
	long long T; cin >> T;
	for(int t=1; t<=T; t++) {
		long long L, R; cin >> L >> R;

		long long diff = myabs(L-R);
		long long n1 = 0;
		if(diff > 0) {
			long long l = 1;
			long long r = 1000000000LL;
			while(l < r) {
				long long mid = (l+r+1)/2;
				long long val = mid*(mid+1)/2;
				if(val < diff)
					l = mid;
				if(val > diff)
					r = mid-1;
				if(val == diff)
					l = r = mid;
			}
			n1 = l;
		}
		if(L < R) {
			R -= n1*(n1+1)/2;
		} else if(L > R) {
			L -= n1*(n1+1)/2;
		}

		bool switched = false;
		if(L < R) {
			switched = true;
			long long tmp = L;
			L = R;
			R = tmp;
		}
		
		long long k, m, n2;
		long long l = 0;
		long long r = 1000000000LL;
		while(l < r) {
			long long mid = (l+r+1)/2;
			long long val = mid*(n1) + mid*mid;
			if(val < L)
				l = mid;
			if(val > L)
				r = mid-1;
			if(val == L)
				l = r = mid;
		}
		k = l;

		l = 0;
		r = 1000000000LL;
		while(l < r) {
			long long mid = (l+r+1)/2;
			long long val = mid*(n1+1) + mid*mid;
			if(val < R)
				l = mid;
			if(val > R)
				r = mid-1;
			if(val == R)
				l = r = mid;
		}
		m = l;

		n2 = 2*mymin(k, m);
		if(k > m) n2 ++;

		k = (n2+1)/2;
		m = n2/2;

		L -= k*n1 + k*k;
		R -= m*(n1+1) + m*m;

		if(switched) {
			long long tmp = L;
			L = R;
			R = tmp;
		}

		cout << "Case #" << t << ": " << n1+n2 << " " << L << " " << R << endl;
	}
}
