#include <iostream>
#include <algorithm>

#define MAX_N 3005
#define f first
#define s second
#define INF 2000000009

using namespace std;

int DP[MAX_N][MAX_N];
int N, M;

int main() {
	cin >> N;

	string cur = "";
	string str;

	for (int i = 0; i < N; i ++) {
		cin >> str;
		cur = (cur + str + cur);
	}
	
	string ans;
	cin >> ans;

	N = ans.size();
	M = cur.size();

	for (int i = 0; i < MAX_N; i ++)
		for (int j = 0; j < MAX_N; j ++)
			DP[i][j] = INF;

	DP[0][0] = 0;

	for (int i = 1; i <= N; i ++) {
		for (int j = 1; j <= M; j ++) {
			DP[i][j] = min(DP[i][j], DP[i - 1][j] + 1);
			DP[i][j] = min(DP[i][j], DP[i][j - 1] + 1);

			if (ans[i - 1] == cur[j - 1])
				DP[i][j] = min(DP[i][j], DP[i - 1][j - 1]);
			else
				DP[i][j] = min(DP[i][j], DP[i - 1][j - 1] + 1);
		}
	}

	cout << DP[N][M] << endl;
	return (0);
}


