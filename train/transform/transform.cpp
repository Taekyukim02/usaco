/*
ID: taekyuk1
TASK: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool areSame(vector< vector<char> > a, vector< vector<char> > b) 
{
	for(int i=0; i<a.size(); i++)
		for(int j=0; j<a.size(); j++)
			if(a[i][j] != b[i][j])
				return false;
	return true;
}

vector<vector<char> > rot(vector<vector<char> > a, int num)
{
	vector<vector<char> > b(a.size(), vector<char>(a.size()));
	for(int i=0; i<a.size(); i++)
		for(int j=0; j<a.size(); j++)
			b[j][a.size()-i-1] = a[i][j];

	if(num == 1)
		return b;
	else
		return rot(b, num-1);
}

vector<vector<char> > ref(vector<vector<char> > a)
{
	vector<vector<char> > b(a.size(), vector<char>(a.size()));
	for(int i=0; i<a.size(); i++)
		for(int j=0; j<a.size(); j++)
			b[i][a.size()-j-1] = a[i][j];
	return b;
}

int main()
{
	ifstream fin ("transform.in");
	ofstream fout ("transform.out");

	// read input
	int N;
	fin >> N;

	vector< vector<char> > grid1(N, vector<char>(N));
	vector< vector<char> > grid2(N, vector<char>(N));

	for(int i=0; i<N; i++) 
		for(int j=0; j<N; j++) 
			fin >> grid1[i][j];

	for(int i=0; i<N; i++) 
		for(int j=0; j<N; j++) 
			fin >> grid2[i][j];

	// print output
	if(areSame(grid2, rot(grid1, 1))) {
		fout << 1 << endl;
		return 0;
	}
	if(areSame(grid2, rot(grid1, 2))) {
		fout << 2 << endl;
		return 0;
	}
	if(areSame(grid2, rot(grid1, 3))) {
		fout << 3 << endl;
		return 0;
	}
	if(areSame(grid2, ref(grid1))) {
		fout << 4 << endl;
		return 0;
	}
	if(areSame(grid2, rot( ref(grid1), 1))
		|| areSame(grid2, rot( ref(grid1), 2))
		|| areSame(grid2, rot( ref(grid1), 3)) ) {
		fout << 5 << endl;
		return 0;
	}
	if(areSame(grid2, grid1)) {
		fout << 6 << endl;
		return 0;
	}
	fout << 7 << endl;
	return 0;
}
