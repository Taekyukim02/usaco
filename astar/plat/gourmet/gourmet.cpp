#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<long long,long long> ii;

ii cows[100000], allg[100000];

int main() {
	int N, M;
	cin >> N >> M;
	
	for(int i=0; i<N; i++) {
		int a, b;
		cin >> a >> b;
		cows[i] = ii(-b, -a);
	}
	for(int i=0; i<M; i++) {
		int a, b;
		cin >> a >> b;
		allg[i] = ii(-b, -a);
	}

	sort(cows, cows+N);
	sort(allg, allg+M);
/*
	cout << endl;
	for(int i=0; i<N; i++)
		cout << cows[i].first << " " << cows[i].second << endl;
	cout << endl;
	for(int i=0; i<M; i++)
		cout << allg[i].first << " " << allg[i].second << endl;
*/
	map <long long, long long> cand;
	long long tot = 0;
	int nIt = 0;
	for(int it = 0; it<N; it++) {
		while(nIt<M && -(allg[nIt].first) >= -(cows[it].first)) {
			if(cand.find(-allg[nIt].second) == cand.end())
				cand[-allg[nIt].second] = 1;
			else
				cand[-allg[nIt].second]++;

			++nIt;
		}
		
//		cout << it << "th cow : " << cand.size() << " available." << endl;
		auto best = cand.lower_bound(-cows[it].second);
		tot += best->first;

//		if(best->second <= 0) { cout << "ERROR" << endl; return 0;}

		if(best->second > 1)
			cand[best->first]--;
		else
			cand.erase(best);
	}

	cout << tot << endl;
	return 0;
}
