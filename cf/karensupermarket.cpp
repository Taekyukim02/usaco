#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> ii;

int N, B, C[5005], D[5005];
vector <int> graph[5005];

int solve(int num) {
	
}

int main() {
	cin >> N >> B;
	C[0] = D[0] = 0;
	graph[0].push_back(1);
	for(int i=1; i<=N; i++) {
		cin >> C[i] >> D[i];
		if(i != 1) {
			int to;
			cin >> to;
			graph[to].push_back(i);
		}
	}
	
	cout << solve(0)-1 << endl;
}
