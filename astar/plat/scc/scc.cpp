#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
vector <int> graph[50000];
int post[50000];

bool visited[50000];
int idx = 0;
void postDfs(int n) {
	visited[n] = true;

	for(int nxt : graph[n]) {
		if(!visited[nxt])
			postDfs(nxt);
	}

	post[idx++] = n;
}

bool alive[50000];
void markDead(int n) {
	alive[n] = false;
	for(int nxt : graph[n])
		if(alive[nxt])
			markDead(nxt);
}

int solve() {
	int ans = 0;
	for(int i=0; i<N; i++)
		alive[i] = true;

	// get topological ordering
	for(int i=0; i<N; i++) {
		if(!visited[i])
			postDfs(i);
	}

	// remove from sink
	for(int i=0; i<N; i++) {
		int n = post[i];
		if(alive[n]) {
			ans++;
			markDead(n);
		}
	}

	return ans;
}

int main() {
	cin >> N;
	for(int i=0; i<N; i++) {
		int a;
		cin >> a;
		graph[i].push_back(a-1);
	}

	cout << solve() << endl;
}
