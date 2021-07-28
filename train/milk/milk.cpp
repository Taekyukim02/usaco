/*
ID: taekyuk1
TASK: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define f first
#define s second

using namespace std;

typedef pair<int,int> ii;

int main()
{
	ifstream fin ("milk.in");
	ofstream fout ("milk.out");

	int N, M;
	fin >> N >> M;

	vector <ii> farmers;
	for(int i=0; i<M; i++) {
		ii a;
		fin >> a.f >> a.s;
		farmers.push_back(a);
	}

	sort(farmers.begin(), farmers.end());

	int totalCost = 0;
	int totalMilk = 0;
	int fId = 0;
	while(totalMilk < N) {
		if(totalMilk + farmers[fId].s <= N) {
			totalMilk += farmers[fId].s;
			totalCost += farmers[fId].f * farmers[fId].s;
//			cout << "bought " << farmers[fId].s << " for " << farmers[fId].f << endl;
		} else {
			totalCost += (N-totalMilk) * farmers[fId].f;
			totalMilk = N;
		}
		fId++;
	}

	fout << totalCost << endl;
	return 0;
}	

