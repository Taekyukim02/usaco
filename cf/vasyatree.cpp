#include <iostream>
#include <queue>
#define f first
#define s second

using namespace std;

typedef pair<int,int> ii;

int N, M;
vector <int> graph[300005];
vector <ii> query[300005];
long long ans[300005];

void solve(int node, int par, priority_queue <ii> Q, int delta, long long sum) {
	// add queries to pqueue
	for(ii x : query[node]) {
		Q.push(ii(-(x.f+delta), x.s));
		sum += x.s;
	}

	// remove < 0 distance queries from pqueue
	while(!Q.empty() && (-Q.top().f)<delta) {
		sum -= Q.top().s;
		Q.pop();
	}

	// set answer[node] to sum of surviving queries
	ans[node] = sum;

	// recurse down tree
	delta++;
	for(int to : graph[node]) {
		if(to != par) {
			solve(to, node, Q, delta, sum);
		}
	}
}

int main() {
	// read input
	cin >> N;
	for(int i=0; i<N-1; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	cin >> M;
	for(int i=0; i<M; i++) {
		int a, b, c; 
		cin >> a >> b >> c;
		query[a].push_back(ii(b,c));
	}

/*
	for(int i=1; i<=N; i++) {
		cout << i << " connected to ";
		for(int to : graph[i])
			cout << to << " ";
		cout << endl;
	}
	*/
	
	// start recursion from node 1
	priority_queue <ii> Q;
	solve(1, -1, Q, 0, 0);

	// print answers
	for(int i=1; i<=N; i++)
		cout << ans[i] << " \n"[i==N];
}
