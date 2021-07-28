#include <iostream>
#include <fstream>
#define f first
#define s second
#define INF 1000000000000ll

using namespace std;

typedef pair<long long,long long> ii;

int N;
ii p[1000];

long long getCost(ii a, ii b) {
	return (a.f-b.f)*(a.f-b.f)+(a.s-b.s)*(a.s-b.s);
}

int main() {
	// read input
	ifstream fin ("moocast.in");
	fin >> N;
	
	for(int i=0; i<N; i++)
		fin >> p[i].f >> p[i].s;
	fin.close();

	// djikstra
	bool visited[1000];
	for(int i=0; i<N; i++) visited[i] = false;
	long long total = 0;
	long long dist[1000];
	for(int i=0; i<N; i++) dist[i] = INF;
	
	dist[0] = 0;
	for(int i=0; i<N; i++) {
		int bestID = 0;
		long long bestDist = INF;

		for(int j=0; j<N; j++)
			if(!visited[j] && bestDist > dist[j]) {
				bestDist = dist[j];
				bestID = j;
			}

		visited[bestID] = true;
		total = max(total, bestDist);

		for(int j=0; j<N; j++)
			dist[j] = min(dist[j], getCost(p[bestID], p[j]));
	}

	// print output
	ofstream fout ("moocast.out");
	fout << total << endl;
	fout.close();
}
