/*
ID: taekyuk1
TASK: game1
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int N, arr[100], pre[101];
	ifstream fin ("game1.in");
	fin >> N;
	pre[0] = 0;
	for(int i=0; i<N; i++) {
		fin >> arr[i];
		pre[i+1] = pre[i] + arr[i];
	}
	fin.close();

	int dp[100][100];
	for(int len=1; len<=N; len++)
		for(int i=0; i+len-1<N; i++) {
			int j = i+len-1;
			if(len==1) dp[i][j] = arr[i];
			else {
				dp[i][j] = max( (pre[j+1]-pre[i]) - dp[i][j-1]
								, (pre[j+1]-pre[i]) - dp[i+1][j] );
			}
		}
	
//	for(int i=0; i<N; i++)
//		for(int j=0; j<N; j++)
//			cout << dp[i][j] << " \n"[j==N-1]; 

	ofstream fout ("game1.out");
	fout << dp[0][N-1] << " " << pre[N]-dp[0][N-1] << endl;
	fout.close();
}
