/*
ID: taekyuk1
TASK: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <set>
#define MAX_N 20

using namespace std;

int A, B, C;
set <int> sol;
bool visited[MAX_N][MAX_N][MAX_N];

void solve(int a, int b, int c) {
	if(visited[a][b][c])
		return;
	visited[a][b][c] = true;

	if(a == 0)
		sol.insert(c);

	if(a+b <= B)	solve(0, a+b, c);
	else 			solve(a+b-B, B, c);
	if(a+b <= A)	solve(a+b, 0, c);
	else 			solve(A, a+b-A, c);

	if(a+c <= C)	solve(0, b, a+c);
	else 			solve(a+c-C, b, C);
	if(a+c <= A)	solve(a+c, b, 0);
	else 			solve(A, b, a+c-A);

	if(b+c <= B)	solve(a, b+c, 0);
	else 			solve(a, B, b+c-B);
	if(b+c <= C)	solve(a, 0, b+c);
	else 			solve(a, b+c-C, C);

	return;
}

int main()
{
	ifstream fin ("milk3.in");
	fin >> A >> B >> C;
	fin.close();

	solve(0,0,C);

	ofstream fout ("milk3.out");
	for(auto it=sol.begin(); it!=sol.end(); ++it) {
		fout << *it;
		if(it != (--sol.end()))
			fout << " ";
		else
			fout << endl;
	}
	fout.close();

	return 0;
}
