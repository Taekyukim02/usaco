#include <iostream>
#include <vector>

#define MAX_N 50

using namespace std;

int N=0;
vector <int> graph[MAX_N+5];
vector <int> rGraph[MAX_N+5];

// solve A
int T[MAX_N+5], bestT[MAX_N+5], t=0;
bool visited[MAX_N+5];

void assignT(int n, int p, vector<int> &A) {
	bestT[n] = T[p];
	T[n] = t++;
	visited[n] = true;
	bool isArt = true;
	for(int to : rGraph[n]) {
		if(to != p) {
			if(visited[to]) {
				bestT[n] = min(bestT[n], T[to]);
			}
			else {
				assignT(to, n, A);
				bestT[n] = min(bestT[n], bestT[to]);
				if(bestT[to] < T[n])
					isArt = false;
			}
		}
	}

	if(isArt)
		A.push_back(n);
	
	return;
}

vector<int> solveA() {
	for(int i=0; i<=N; i++)
		T[i] = bestT[i] = 987654321;

	vector <int> artP;
	assignT(N, -1, artP);

	for(int i=0; i<artP.size(); ) {
		if(artP[i] == 0 || artP[i] == N)
			artP.erase(artP.begin()+i);
		else
			i++;
	}

	for(int i=0; i<=N; i++)
		cout << i << " " << T[i] << " " << bestT[i] << endl;

	return artP;
}

vector<int> solveB(vector<int> ans1) {
	return ans1;
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
