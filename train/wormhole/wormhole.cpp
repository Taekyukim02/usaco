/*
ID: taekyuk1
TASK: wormhole
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define f first
#define s second
#define MAX_N 12

using namespace std;

typedef pair<int,int> ii;

int counter;
int N;
vector <ii> points;
map <int, set<ii> > mp;

// process method
void process(int pairing[]) {
	for(int i=0; i<N; i++) {
		bool visited[MAX_N];
		for(int i=0; i<MAX_N; i++) visited[i] = false;
			
		queue <int> toVisit;
		toVisit.push(i);
		while(!toVisit.empty()) {
			int id = toVisit.front();
			toVisit.pop();
			
//			cout << "on id " << id << endl;
			if(visited[id]) {
//				cout << "ended" << endl;
				counter++;
				return;
			}
			visited[id] = true;

			ii xy = points[id];
			if(mp[xy.s].find( make_pair(xy.f,id) ) != --(mp[xy.s].end())) {
				toVisit.push(pairing[ (++mp[xy.s].find( make_pair(xy.f, id) ))->s ]);
			}
		}

//		cout << "----------" << endl;
	}

//  for(int i=0; i<N; i++)
//  	cout << i << " -- " << pairing[i] << endl;
//  cout << endl;
}

// getPair method
void getPair(int pairing[], vector<int> remaining) {
	if(remaining.empty()) {
		process(pairing);
		return;
	}

	int f = remaining[0];
	remaining.erase(remaining.begin());
	
	for(vector<int>::iterator it = remaining.begin(); it<remaining.end(); it++) {
		int s = *it;
		pairing[f] = s;
		pairing[s] = f;
		remaining.erase(it);
		getPair(pairing, remaining);
		remaining.insert(it, s);
	}
}

// main method
int main() {
	ifstream fin ("wormhole.in");
	ofstream fout ("wormhole.out");
	
	// read input
	fin >> N;
	for(int i=0; i<N; i++) {
		ii a;
		fin >> a.f >> a.s;
		points.push_back(a);
		mp[a.s].insert( make_pair(a.f, i) );
	}

	// getPairs then process
	counter = 0;
	vector <int> remaining(N);
	for(int i=0; i<N; i++)
		remaining[i] = i;

	int pairing[MAX_N] = {};
	getPair(pairing, remaining);

	fout << counter << endl;
	return 0;
}
