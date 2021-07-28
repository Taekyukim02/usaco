#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define f first
#define s second

using namespace std;

typedef pair<int,int> ii;
typedef pair<ii, int> pii;

int R, C;
string grid[50];
int id[50][50];
vector <ii> graph[15];
vector <ii> nodes[15];

void fill(int num, int i, int j) {
	if(i<0 || j<0 || i>=R || j>=C || grid[i][j] != 'X' || id[i][j] != -1)
		return;
	
	id[i][j] = num;
	nodes[num].push_back(ii(i, j));

	fill(num, i+1, j  );
	fill(num, i-1, j  );
	fill(num, i  , j+1);
	fill(num, i  , j-1);
}

int main() {
	// read in grid
	cin >> R >> C;
	for(int i=0; i<R; i++)
		cin >> grid[i];
	
	// initialize grid
	for(int i=0; i<50; i++)
		for(int j=0; j<50; j++)
			id[i][j] = -1;

	// create id and id list
	int num=0;
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++) 
			if(id[i][j] == -1 && grid[i][j] == 'X') {
				fill(num, i, j);
				num++;
			}

	// create edges between ID
	for(int i=0; i<num; i++) {
		bool visited[50][50];
		for(int j=0; j<50; j++)
			for(int k=0; k<50; k++)
				visited[j][k] = false;

		bool found[20];
		for(int j=0; j<20; j++)
			found[j] = false;
		found[i] = true;

		queue <pii> bfs;
		for(ii x : nodes[i])
			bfs.push(pii(x,0));
		while(!bfs.empty()) {
			pii k = bfs.front();
			ii x = k.f;
			int t = k.s;
//			cout << "tried " << x.f << " " << x.s << endl;
			bfs.pop();
			
			if(x.f < 0 || x.s < 0 || x.f >= R || x.s >= C
				|| grid[x.f][x.s] == '.' || visited[x.f][x.s])
				continue;

			visited[x.f][x.s] = true;

			if(id[x.f][x.s] > -1 && !found[id[x.f][x.s]]) {
				graph[i].push_back(ii(id[x.f][x.s], t-1));
				found[id[x.f][x.s]] = true;
				continue;
			}

			bfs.push(pii(ii(x.f  , x.s+1), t+1));
			bfs.push(pii(ii(x.f+1, x.s  ), t+1));
			bfs.push(pii(ii(x.f  , x.s-1), t+1));
			bfs.push(pii(ii(x.f-1, x.s  ), t+1));
		}
	}

/*
	// check
	cout << num << endl;
	for(int i=0; i<num; i++) {
		cout << "from " << i << " to:" << endl;
		for(int to : graph[i])
			cout << to << " ";
		cout << endl;
	}
	*/

	// traveling salesman algorithm
	int dp[15][(1<<15)];
	for(int i=0; i<15; i++) {
		for(int j=0; j<(1<<15); j++)
			dp[i][j] = 111111;
		dp[i][(1<<i)] = 0;
	}
	
	for(int j=0; j<(1<<num); j++)
		for(int i=0; i<num; i++)
			if((1<<i) & j)
				for(ii to : graph[i]) {
					dp[to.f][j | (1<<to.f)] = min(dp[to.f][j | (1<<to.f)],
											dp[i][j] + to.s);
				}

	int minimum = 987654321;
	for(int i=0; i<num; i++)
		minimum = min(minimum, dp[i][(1<<num)-1]);

	cout << minimum << endl;
}
