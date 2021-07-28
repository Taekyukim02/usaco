/*
ID: taekyuk1
TASK: combo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <map>
#define f first
#define s second

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int main()
{
	ifstream fin ("combo.in");
	ofstream fout ("combo.out");

	int N;
	iii a, b;
	fin >> N >> a.f >> a.s.f >> a.s.s >> b.f >> b.s.f >> b.s.s;

	map <iii, int> mp;
	for(int i=-2; i<3; i++)
		for(int j=-2; j<3; j++)
			for(int k=-2; k<3; k++) {
				mp[make_pair((a.f+N+i)%N, make_pair((a.s.f+N+j)%N, (a.s.s+N+k)%N))] = 1;
				mp[make_pair((b.f+N+i)%N, make_pair((b.s.f+N+j)%N, (b.s.s+N+k)%N))] = 1;
			}

	fout << mp.size() << endl;
}
