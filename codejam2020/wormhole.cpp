#include <iostream>

using namespace std;

long long N, X[10], Y[10];
int connected[10];
int ans;

// gcd(dX, dY) == 1
int findNext(int i, long long dX, long long dY) {
	int bestj = -1;
	long long bestK = 987654321;
	for(int j=0; j<N; j++) {
		if(i == j) continue;

		if(dX*(Y[j] - Y[i]) == dY*(X[j]-X[i])) {
			if(dX != 0 && dX*(X[j]-X[i]) > 0) {
				long long k = (X[j]-X[i])/dX;
				if(k < bestK) {
					k = bestK;
					bestj = j;
				}
			} else if(dY != 0 && dY*(Y[j]-Y[i]) > 0) {
				long long k = (Y[j]-Y[i])/dY;
				if(k < bestK) {
					k = bestK;
					bestj = j;
				}
			}
		}
	}
	
	return bestj;
}

void solve() {
	for(int a=0; a<N; a++) {
		for(int b=0; b<N; b++) {
			if(a == b) continue;

			bool seen[10];
			for(int i=0; i<10; i++)
				seen[i] = 0;
			seen[a] = seen[b] = 1;
			
			long long dX = X[b] - X[a];
			long long dY = Y[b] - Y[a];

			int k = connected[b];
			int counter = 0;
			while(counter < 100 && k != -1) {
				seen[k] = 1;
				k = findNext(k, dX, dY);
				if(k != -1) {
					seen[k] = 1;
					k = connected[k];
				}
				counter ++;
			}

			int thisans = 0;
			for(int i=0; i<10; i++)
				if(seen[i]) thisans++;

			if(thisans > ans)
				ans = thisans;
		}
	}
}

void recurse(int curr) {
	if(curr == N) {
		solve();
		return;
	}

	if(connected[curr] != -1)
		recurse(curr + 1);

	recurse(curr + 1); //don't connect

	for(int i=curr+1; i<N; i++) {
		if(connected[i] != -1) continue;	// already connected

		connected[curr] = i;
		connected[i] = curr;
		recurse(curr + 1);
		connected[curr] = connected[i] = -1;
	}
}

int main() {
	int T; cin >> T;
	for(int t=1; t<=T; t++) {
		cin >> N;
		for(int i=0; i<N; i++)
			cin >> X[i] >> Y[i];

		for(int i=0; i<10; i++)
			connected[i] = -1;
		
		ans = 1;
		recurse(0);
		
		cout << "Case #"<<t<<": " << ans << endl;
	}
}
