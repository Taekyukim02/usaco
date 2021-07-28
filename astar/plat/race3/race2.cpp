#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 50

using namespace std;

int N=0;
vector <int> graph[MAX_N+5];
vector <int> rGraph[MAX_N+5];

// solve A
bool visited[MAX_N+5];
int path[MAX_N+5], num=0;
bool need[MAX_N+5];

void dfs(int n) {
	if(n == N) {
		bool temp[100];
		for(int i=0; i<=N; i++)
			temp[i] = false;

		for(int i=0; i<num; i++) {
			temp[path[i]] = true;
		}
		for(int i=0; i<=N; i++)
			need[i] &= temp[i];

		return;
	}
	
	for(int to : graph[n]) {
		if(!visited[to]) {
			visited[to] = true;
			path[num++] = to;
			dfs(to);
			num--;
			visited[to] = false;
		}
	}

	return;
}

vector<int> solveA() {
	for(int i=0; i<=N; i++)
		need[i] = true;

	visited[0] = true;
	path[num++] = 0;
	dfs(0);

	vector <int> ans;
	for(int i=1; i<N; i++)
		if(need[i])
			ans.push_back(i);
	
	return ans;
}

bool visited1[MAX_N+5];
bool visited2[MAX_N+5];

void markVisited1(int n) {
	visited1[n] = true;
	for(int to : graph[n])
		if(!visited1[to])
			markVisited1(to);
	return;
}
void markVisited2(int n) {
	visited2[n] = true;
	for(int to : rGraph[n])
		if(!visited2[to])
			markVisited2(to);
	return;
}

vector<int> solveB(vector<int> ans1) {
	vector <int> ans2;
	for(int n : ans1) {
		for(int i=0; i<=N; i++)
			visited1[i] = visited2[i] = false;

		markVisited1(n);
		markVisited2(n);

		bool good = true;
		for(int i=0; i<=N; i++) {
			if(visited1[i] && visited2[i] && i != n)
				good = false;
		}
		if(good)
			ans2.push_back(n);

	}

	return ans2;
}

int main() {
	// read input
	int c; cin >> c;
	while(c != -1) {
		if(c == -2)
			N++;
		else {
			graph[N].push_back(c);
			rGraph[c].push_back(N);
		}
		cin >> c;
	}

	N--;

	// solve A
	vector <int> ans1 = solveA();
	sort(ans1.begin(), ans1.end());
	cout << ans1.size() << " ";
	for(int i : ans1)
		cout << i << " ";
	cout << endl;

	// solve B
	vector <int> ans2 = solveB(ans1);
	sort(ans2.begin(), ans2.end());
	cout << ans2.size() << " ";
	for(int i : ans2)
		cout << i << " ";
	cout << endl;

	return 0;
}
