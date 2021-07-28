#include <iostream>
#define f first
#define s second

using namespace std;

typedef pair<long long, long long> ii;

int N, K;
long long A[200];
ii fact[200];

// biggest dividing exponent
long long bde(long long a, long long b) {
	long long ans=0;
	while(a%b == 0) {
		a /= b;
		ans++;
	}
	return ans;
}

bool used[200];

int main() {
	cin >> N >> K;
	for(int i=0; i<N; i++)
		cin >> A[i];
	
	for(int i=0; i<N; i++)
		fact[i] = ii(bde(A[i], 2), bde(A[i], 5));
	
	ii curr = ii(0,0);
	for(int i=0; i<K; i++) {
		ii best = ii(-1, -1);
		int idx = -1;
		for(int j=0; j<N; j++)
			if(!used[j]) {
				ii res = ii(curr.f+fact[j].f, curr.s+fact[j].s);
				if(min(best.f, best.s) < min(res.f, res.s)
					|| (min(best.f, best.s) == min(res.f, res.s)
						&& best.f+best.s < res.f+res.s)) {
					best = res;
					idx = j;
				}
			}

		used[idx] = true;
		curr = best;
	}

	cout << min(curr.f, curr.s) << endl;
}
