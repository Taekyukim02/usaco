/*
ID: taekyuk1
TASK: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
#define MAX_R 1000

using namespace std;

int main()
{
	ifstream fin ("numtri.in");

	int R; 
	fin >> R;

	int grid[MAX_R][MAX_R];
	for(int i=0; i<R; i++)
		for(int j=0; j<=i; j++)
			fin >> grid[i][j];

	fin.close();

	int ans[MAX_R][MAX_R];
	for(int j=0; j<R; j++)
		ans[R-1][j] = grid[R-1][j];
	
	for(int i=R-2; i>=0; i--)
		for(int j=0; j<=i; j++)
			ans[i][j] = grid[i][j] + max(ans[i+1][j], ans[i+1][j+1]);

	ofstream fout ("numtri.out");
	fout << ans[0][0] << endl;
	fout.close();

	return 0;
}
