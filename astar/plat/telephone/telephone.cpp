#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector <int> graph[100000];
int weight[100000];
int carry[100000];

int cnt = 0;

void setLeaf(int n, int p) {
	for(int to : graph[n]) {
		if(to == p) continue;
		setLeaf(to, n);
	}

	if(graph[n].size() == 1)
		carry[n] = 1;
}

void traverse(int n, int p) {
	for(int to : graph[n]) {
		if(p == to) continue;
		traverse(to, n);
	}
	// deal with previous carries
	while(carry[n] >= 2 && weight[n]) {
		carry[n] -= 2;
		weight[n]--;
		cnt++;
	}
	if(weight[n] == 0)
		carry[n] = 0;

	if(p == -1) return;

	// we are a leaf now
	carry[p] += carry[n]%2;
}

int main() {
	cin >> N >> K;
	for(int i=0; i<N-1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}

	for(int i=0; i<N; i++)
		weight[i] = K;

	setLeaf(rand()%N, -1);
//	for(int i=0; i<N; i++)
//		cout << carry[i] << " \n"[i==N-1];

	traverse(rand()%N, -1);

	cout << cnt << endl;
}
