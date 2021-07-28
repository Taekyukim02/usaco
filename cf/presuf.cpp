#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> ii;

int N;
string strList[200];
vector <ii> order;

int main() {
	cin >> N;
	for(int i=0; i<2*(N-1); i++) {
		cin >> strList[i];
		order.emplace_back(strList[i].length(), i);
	}

	sort(order.begin(), order.end());

	string cand = strList[order[2*N-3].second] + strList[order[2*N-4].second][N-2];
	bool pref[200];
	bool bad = false;
	for(int i=0; i<N-1; i++) {
		if(cand.substr(0, i+1) == strList[order[2*i].second]
			&&	cand.substr(N-(i+1)) == strList[order[2*i+1].second]) {
			pref[order[2*i].second] = true;
			pref[order[2*i+1].second] = false;
		}
		else if(cand.substr(0, i+1) == strList[order[2*i+1].second]
			&&	cand.substr(N-(i+1)) == strList[order[2*i].second]) {
			pref[order[2*i+1].second] = true;
			pref[order[2*i].second] = false;
		}
		else {
			bad = true;
			break;
		}
	}

	if(bad) {

		string cand = strList[order[2*N-4].second] + strList[order[2*N-3].second][N-2];
		for(int i=0; i<N-1; i++) {
			if(cand.substr(0, i+1) == strList[order[2*i].second]
				&&	cand.substr(N-(i+1)) == strList[order[2*i+1].second]) {
				pref[order[2*i].second] = true;
				pref[order[2*i+1].second] = false;
			}
			else if(cand.substr(0, i+1) == strList[order[2*i+1].second]
				&&	cand.substr(N-(i+1)) == strList[order[2*i].second]) {
				pref[order[2*i+1].second] = true;
				pref[order[2*i].second] = false;
			}
		}

	}

	for(int i=0; i<2*(N-1); i++)
		if(pref[i])
			cout << "P";
		else
			cout << "S";
	cout << endl;
	return 0;
}
