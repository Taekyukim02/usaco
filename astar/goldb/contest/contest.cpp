#include <iostream>
#define MAX_N 101

using namespace std;

int skill[MAX_N][MAX_N];
bool visited[MAX_N];

int rankedUpOrDown(int c, int d) {
	int res = 0;
	for(int i=0; i<MAX_N; i++) 
		if(skill[c][i] == d && !visited[i]) {
			visited[i] = true;
			res += 1 + rankedUpOrDown(i, d);
		}

	return res;
}

int main() {
	// read input
	int N, M;
	cin >> N >> M;

	
	for(int i=0; i<M; i++) {
		int a, b;
		cin >> a >> b;
		skill[a][b] = 1;
		skill[b][a] = -1;
	}

	// iterate through all cows
	int count = 0;
	for(int i=1; i<=N; i++) {
		int a = rankedUpOrDown(i, 1);
			for(int i=1; i<=N; i++) visited[i] = false;
		int b = rankedUpOrDown(i, -1);
			for(int i=1; i<=N; i++) visited[i] = false;
		if(a + b + 1 == N)
			count++;
	}
	cout << count << endl;
}
