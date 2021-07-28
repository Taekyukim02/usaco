/*
ID: taekyuk1
TASK: range
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	int N;
	string str[250];
	ifstream fin ("range.in");
	fin >> N;
	for(int i=0; i<N; i++)
		fin >> str[i];
	
	int cnt[251];
	int tot = 0;
	int grid[250][250];
	for(int i=0; i<250; i++)
		cnt[i] = 0;
	
	for(int i=N-2; i>=0; i--) 
		for(int j=N-2; j>=0; j--)  {
			if(i==N-2 || j==N-2) { 		// check only the 2x2 square
				grid[i][j] = 0;
				if(str[i][j] == '1')
					grid[i][j] = 1;
				if(str[i][j] == '1' && str[i+1][j] == '1'
					&& str[i][j+1] == '1' && str[i+1][j+1] == '1')
					grid[i][j] = 2;
			}
			else {
				grid[i][j] = min( min(grid[i+1][j], grid[i][j+1])
								, grid[i+1][j+1]) + 1;
				if(str[i][j] == '0')
					grid[i][j] = 0;
			}
			tot++;
			cnt[grid[i][j]]++;
		}
	
	/*
	for(int i=0; i<N; i++)
	for(int j=0; j<N; j++)
		cout << grid[i][j] << " \n"[j==N-1];
	*/

	ofstream fout ("range.out");
	for(int i=0; i<=250; i++) {
		if(i>=2 && cnt[i])
			fout << i << " " << tot << endl;
		tot-=cnt[i];
	}
	fout.close();

	return 0;
}
