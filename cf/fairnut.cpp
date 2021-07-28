#include <iostream>
#include <random>
#include <chrono>

#define MAX_N 300000
#define f first
#define s second

using namespace std;

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <long long, long long> ii;

int N;
long long w[MAX_N+5];
vector <ii> graph[MAX_N+5];

long long mymax(long long a, long long b) {
	return (a<b) ? b : a;
}

long long bestDist = 0;
long long solve(int node, int par) {
	long long currDist = w[node];
	long long d1 = -1, d2 = -1;
	int cnt=0;
	for(ii to : graph[node]) {
		if(to.f != par) {
			cnt++;
			long long ret = solve(to.f, node);
			if(ret + w[node] - to.s > d2)
				d2 = ret + w[node] - to.s;
			if(ret + w[node] - to.s > d1) {
				d2 = d1;
				d1 = ret + w[node] - to.s;
			}
			currDist = mymax(currDist, ret + w[node] - to.s);
		}
	}

	// update bestDist
	bestDist = mymax(bestDist, currDist);
	if(cnt > 1)
		bestDist = mymax(bestDist, d1 + d2 - w[node]);

	return currDist;
}

int main() {
	// read input
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> w[i];
	}
	for(int i=0; i<N-1; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		graph[a].push_back(ii(b, c));
		graph[b].push_back(ii(a, c));
	}

	// dp
	int root = rng32() % N;
	solve(root, -1);

	// print answer
	cout << bestDist << endl;
}
