#include <iostream>
#include <vector>
#include <iomanip>
#define f first
#define s second

using namespace std;

typedef pair<int,int> ii;

int L, P, F[1005];
vector<ii> graph[1005];

// return true if cycle w/ edge sum < t
bool negCycle(double t) {
	double dist[1005];
	for(int i=0; i<1005; i++)
		dist[i] = 987654321;
	
	// start at 0
	for(ii to : graph[0]) {
		dist[to.f] = -F[to.f];
	}

	// relax distances L-1 times
	for(int j=0; j<L+1; j++) {
		for(int i=1; i<=L; i++) {
			for(ii to : graph[i]) {
				if(dist[to.f] > dist[i] + to.s*t - F[to.f])
					dist[to.f] = dist[i] + to.s*t - F[to.f];
			}
		}
	}

	// check if relax N times gives better result
	for(int i=1; i<=L; i++) {
		for(ii to : graph[i]) {
			if(dist[to.f] > dist[i] + to.s*t - F[to.f])
				return true;		// negative cycle exists
		}
	}
	return false;
}

int main() {
	// read input
	cin >> L >> P;
	for(int i=1; i<=L; i++)
		cin >> F[i];
	for(int i=0; i<P; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(ii(b, c));
	}

	// add '0' node
	for(int i=1; i<=L; i++)
		graph[0].push_back(ii(i, 0));

	// binary search on answer
	double low=0, high=1000;
	double e = 0.00001;
	while(low < high-e) {
		double mid = (low+high)/2;
		if(negCycle(mid)) {
			low = mid;
		}
		else {
			high = mid;
		}
	}

	// output answer
	cout << fixed << setprecision(2) << low << endl;
}
