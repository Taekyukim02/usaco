#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> graph[500];
int stk[10000];

int num=0;
void find_circuit(int n) {
	while(!graph[n].empty()) {
		int to = graph[n][0];
		graph[n].erase(graph[n].begin());
		for(auto it=graph[to].begin(); it!=graph[to].end(); ++it) {
			if(*it == n) {
				graph[to].erase(it);
				break;
			}
		}
		find_circuit(to);
	}

	stk[num++] = n;
}

int main() {
	int F, smallest = 987654321;
	cin >> F;
	for(int i=0; i<F; i++) {
		int a, b;
		cin >> a >> b;
		smallest = min(smallest, min(a, b));
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for(int i=1; i<=500; i++)
		sort(graph[i].begin(), graph[i].end());
	
	int start = -1;
	for(int i=1; i<=500; i++) {
		if(start == -1 && graph[i].size()%2) {
			start = i;
			break;
		}
	}

	if(start == -1)
		start = smallest;
	
	find_circuit(start);

	while(num>0) {
		cout << stk[--num] << endl;
	}
}
