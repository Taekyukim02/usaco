/*
ID: taekyuk1
TASK: skidesign
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define diff 17

using namespace std;

int findCost(vector <int> h, int l, int r) {
	int cost = 0;
	for(int i : h) {
		if(i<l) cost += (l-i)*(l-i);
		if(r<i) cost += (i-r)*(i-r);
	}
	return cost;
}

int main() {
	ifstream fin ("skidesign.in");
	ofstream fout ("skidesign.out");

	int N;
	fin >> N;
	
	vector <int> h;
	for(int i=0; i<N; i++) {
		int a;
		fin >> a;
		h.push_back(a);
	}

	sort(h.begin(), h.end());

	int minCost = 100000000;
	for(int i=h[0]; i<=h[h.size()-1]-diff; i++) {
		minCost = min(minCost, findCost(h, i, i+diff));
	}

	fout << minCost << endl;
	return 0;
}
