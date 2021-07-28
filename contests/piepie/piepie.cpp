#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#define MAX_N 200000
#define f first
#define s second

using namespace std;

typedef pair<int,int> ii;

int a1[2*MAX_N], a2[2*MAX_N];
int main()
{
	ifstream fin ("piepie.in");
	ofstream fout ("piepie.out");
	int N, D;
	fin >> N >> D;

	queue <ii> bfs; 		// 0~ (N-1) -> Bessie's pie must be given
							// N~(2N-1) -> 2nd cow's pie must be given

	set <ii> searchA;
	set <ii> searchB;

	// read input
	for(int i=0; i<N; i++) {
		fin >> a1[i] >> a2[i];
		searchA.insert(make_pair(a2[i], i));
		if(a2[i] == 0)
			bfs.push(make_pair(i, 1));
	}
	
	for(int i=N; i<2*N; i++) {
		fin >> a2[i] >> a1[i];
		searchB.insert(make_pair(a2[i], i));
		if(a2[i] == 0)
			bfs.push(make_pair(i, 1));
	}

	int A[2*MAX_N];
	for(int i=0; i<2*N; i++)
		A[i] = -1;

	// bfs
	while(!bfs.empty()) {
		ii x = bfs.front();
		bfs.pop();

		// update A[]
		if(A[x.f] == -1 || A[x.f] > x.s)
			A[x.f] = x.s;
		else
			continue;

		// push possible "previous" pies
		int ownerValue = a1[x.f];
		if(x.f < N) {
			for(auto it = searchB.lower_bound(make_pair(ownerValue-D,0));
					it != searchB.upper_bound(make_pair(ownerValue,1000000001));
					++it)
				bfs.push( make_pair(it->s, x.s+1));
		} else {
			for(auto it = searchA.lower_bound(make_pair(ownerValue-D,0));
					it != searchA.upper_bound(make_pair(ownerValue,1000000001));
					++it)
				bfs.push( make_pair(it->s, x.s+1));
		}
	}


	// print output
	for(int i=0; i<N; i++)
		fout << A[i] << endl;

	return 0;
}
