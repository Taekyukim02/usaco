#include <iostream>
#include <vector>
#define MAX_N 1000
#define INF 10000000000000

using namespace std;

typedef pair<int,int> ii;
typedef pair<long long, int> li;

int A, B, N;
vector <ii> path[MAX_N+1];
vector < vector <int> > routes;

long long c[MAX_N+1];

int main() {
	// read input
	cin >> A >> B >> N;

	for(int i=0; i<N; i++) {
		int n;
		cin >> c[i] >> n;
		vector <int> r;
		for(int j=0; j<n; j++) {
			int l; 
			cin >> l;
			r.push_back(l);
			path[l].push_back( ii(i, j) );
		}
		routes.push_back(r);
	}

	// bfs
	bool visited[MAX_N+1];
	for(int i=0; i<=MAX_N; i++)
	    visited[i] = false;
	li cf[MAX_N+1];
	for(int i=0; i<=MAX_N; i++)
		cf[i] = li(INF, 0);
	
	cf[A] = li(0,0);

	while(true) {
		int bestID = -1;
		long long bestDist = INF;
		long long bestFlight = INF;
		for(int i=1; i<=MAX_N; i++) {
			if(!visited[i] && (bestDist > cf[i].first || 
			                    (bestDist < INF && bestDist == cf[i].first && bestFlight > cf[i].second))) {
				bestID = i;
				bestDist = cf[i].first;
				bestFlight = cf[i].second;
			}
		}

		if(bestID == -1) {
			cout << "-1 -1" << endl; 	//nothing found
			break;
		}

		if(bestID == B) {
			cout << bestDist << " " << cf[bestID].second << endl;
			break;
		}

		visited[bestID] = true;

		// try to extend to neighbors
		for(ii b : path[bestID]) {
			for(int i=b.second+1; i<routes[b.first].size(); i++) {
				if(bestDist + c[b.first] < cf[routes[b.first][i]].first ||
				      (bestDist + c[b.first] == cf[routes[b.first][i]].first &&
				            cf[bestID].second+(i-b.second) < cf[routes[b.first][i]].second) )
					cf[routes[b.first][i]] = li(bestDist + c[b.first], cf[bestID].second+(i-b.second));
			}
		}
	}

	// done
	return 0;
}
