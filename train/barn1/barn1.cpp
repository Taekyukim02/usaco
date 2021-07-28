/*
ID: taekyuk1
TASK: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ifstream fin ("barn1.in");
	ofstream fout ("barn1.out");

	int M, S, C;
	fin >> M >> S >> C;

	vector <int> b;
	for(int i=0; i<C; i++) {
		int a; fin >> a;
		b.push_back(a);
	}

	sort(b.begin(), b.end());

	vector <int> dif;
	for(int i=0; i<b.size()-1; i++)
		dif.push_back(b[i+1] - b[i]-1);

	sort(dif.begin(), dif.end());

	int erase = 0;
	int id=dif.size()-1;
	for(int i=0; i<M-1 && id>=0; i++, id--) {
		erase += dif[id];
		cout << dif[id] << endl;
	}

	fout << S - erase - (b[0]-1) - (S-b[b.size()-1]) << endl;
	return 0;
}

