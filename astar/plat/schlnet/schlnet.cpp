#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100

using namespace std;

int N;
vector <int> graph[MAX_N+5];

// solve A methods
int order[MAX_N + 5];
int orderIdx = 0;
bool visited[MAX_N+5];

void topSort(int n) {
	visited[n] = true;
	for(int to : graph[n]) {
		if(!visited[to])
			topSort(to);
	}

	order[orderIdx++] = n;
}

void markVisited(int n) {
	visited[n] = true;
	for(int to : graph[n]) {
		if(!visited[to])
			markVisited(to);
	}
}

int solveA() {
	for(int i=0; i<N; i++)
		if(!visited[i])
			topSort(i);
	
	reverse(order, order+N);

	for(int i=0; i<N; i++)
		visited[i] = false;

	int ans = 0;
	for(int i=0; i<N; i++) {
		if(!visited[order[i]]) {
			markVisited(order[i]);
			ans++;
		}
	}
	
	return ans;
}

// solve B methods
vector <int> rGraph[MAX_N+5];

void markRVisited(int n) {
	visited[n] = true;
	for(int to : rGraph[n]) {
		if(!visited[to])
			markRVisited(to);
	}
}

int solveB() {
	for(int i=0; i<N; i++)
		visited[i] = false;

	int ans1=0, ans2=0;
	// start from sink nodes, and mark all ancestor nodes (including cycles)
	for(int i=N-1; i>=0; i--) {
		if(!visited[order[i]]) {
			markRVisited(order[i]);
			ans1++;
		}
	}
	
	for(int i=0; i<N; i++)
		visited[i] = false;
	// start from all top nodes
	for(int i=0; i<N; i++) {
		if(!visited[order[i]]) {
			markVisited(order[i]);
			ans2++;
		}
	}
	
	return max(ans1, ans2);
}

int main() {
	// read input
	cin >> N;
	for(int i=0; i<N; i++) {
		int c;
		cin >> c;
		while(c != 0) {
			graph[i].push_back(c-1);
			rGraph[c-1].push_back(i);
			cin >> c;
		}
	}

	// solve A
	cout << solveA() << endl;

	// solve B
	cout << solveB() << endl;

	return 0;
}
