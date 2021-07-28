#include <iostream>
#include <fstream>

using namespace std;

int N, K;
string str;
int dp[300000];

int main() {
	ifstream fin ("redistricting.in");
	fin >> N >> K;
	fin >> str;
	fin.close();

	dp[0] = (str[0] == 'G');
	for(int i=1; i<N; i++) {
		dp[i] = 987654321;
		int tot = 1;
		int G = (str[i] == 'G');
		for(int j=i-1; j>=0 && i-j<=K; j--) {
//			cout << "ran " << i << " " << G << " " << tot << endl;
			dp[i] = min(dp[i], dp[j] + (2*G >= tot));

			G += (str[j] == 'G');
			tot++;
		}
		if(i<K)
			dp[i] = min(dp[i], (int) (2*G>=tot));
	}

	ofstream fout ("redistricting.out");
//	for(int i=0; i<N; i++)
//		cout << dp[i] << " \n"[i==N-1];
	fout << dp[N-1] << endl;
	fout.close();
}
