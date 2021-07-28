/*
ID: taekyuk1
TASK: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool bs[2*250*250+1];

int main()
{
	ifstream fin ("ariprog.in");
	ofstream fout ("ariprog.out");

	// read input
	int N, M;
	fin >> N >> M;
	fin.close();

	// build set of bisquares
	for(int i=0; i<=M; i++)
		for(int j=0; j<=M; j++)
			bs[i*i + j*j] = 1;

	// try arithmetic progressions
	vector < pair<int,int> > sol;
	bool printed = false;
	for(int d = 1; d <= 2*M*M; d++) {
		if(d*(N-1) > 2*M*M)
			break;
		for(int a=0; a<d; a++) {
			int counter = 0;
			bool skipped = false;
			for(int i=0; a+d*i <= 2*M*M;) {
				if(bs[a+d*i] == 0) {
					counter = 0;
					skipped = true;
					i += 2;
				}
				else {
					if(skipped) {
						i--;
						skipped = false;
					}
					else {
						counter++;
						if(counter >= N)
							sol.push_back( make_pair(d, a+d*(i-N+1)));
						i++;
					}
				}
			}
		}
	}
	
	sort(sol.begin(), sol.end());

	// print output
	for(pair<int,int> x : sol)
		fout << x.second << " " << x.first << endl;
	if(sol.empty())
		fout << "NONE" << endl;

	return 0;
}
