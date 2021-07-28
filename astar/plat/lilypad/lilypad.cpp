#include <iostream>
#include <vector>
#include <queue>

#define f first
#define s second
#define MAX_N 30

using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> pii;

int grid[MAX_N+5][MAX_N+5];
int ID[MAX_N+5][MAX_N+5];
vector <ii> groups[MAX_N * MAX_N + 5];
int M, N;

int numGroup = 0;
bool visited[MAX_N+5][MAX_N+5];
int dp[MAX_N+5][MAX_N+5];

void makeGroup(int i, int j, int id) {
	// check for valid spot
	if(i < 0 || j < 0 || i >= M || j >= N
		|| ID[i][j] != -1 || grid[i][j] == 0
		|| grid[i][j] == 2)
		return;

	// put (i, j) into id group
	groups[id].push_back(ii(i, j));
	ID[i][j] = id;

	// push neighboring lilypads
	makeGroup(i+1, j+2, id);
	makeGroup(i+1, j-2, id);
	makeGroup(i-1, j+2, id);
	makeGroup(i-1, j-2, id);

	makeGroup(i+2, j+1, id);
	makeGroup(i+2, j-1, id);
	makeGroup(i-2, j+1, id);
	makeGroup(i-2, j-1, id);
}

int main() {
	ii S, E;
	
	// read input
	cin >> M >> N;
	for(int i=0; i<M; i++)
		for(int j=0; j<N; j++) {
			cin >> grid[i][j];
			if(grid[i][j] == 3)
				S = ii(i, j);
			if(grid[i][j] == 4)
				E = ii(i, j);
		}
	
	// create groups of cost 0 lilypads
	for(int i=0; i<M; i++)
		for(int j=0; j<N; j++)
			ID[i][j] = -1;

	for(int i=0; i<M; i++)
		for(int j=0; j<N; j++)
			if(ID[i][j] == -1 && grid[i][j] != 0
							  && grid[i][j] != 2) {
				makeGroup(i, j, numGroup);
				numGroup++;
			}

/*
	// debug
	for(int i=0; i<M; i++)
		for(int j=0; j<N; j++)
			cout << ID[i][j] << " \n"[j==N-1];
	cout << endl;

	for(int i=0; i<numGroup; i++) {
		for(ii to : groups[i])
			cout << to.f << " " << to.s << "     ";
		cout << endl;
	}
	*/

	// bfs from start
	int ans = -1;

	queue <pii> Q;
	for(ii start : groups[ID[S.f][S.s]]) {
		Q.push(pii(start, 0));
		visited[start.f][start.s] = true;
		dp[start.f][start.s] = 1;
	}
	while(!Q.empty()) {
		pii x = Q.front();
		Q.pop();

		// rock
		if(grid[x.f.f][x.f.s] == 2)
			continue;
		// open water -- add lilypad
		if(grid[x.f.f][x.f.s] == 0)
			x.s++;

	//	cout << "at " << x.f.f << " " << x.f.s << "  " << x.s << endl;

		// reached end lilypad
		if(x.f.f == E.f && x.f.s == E.s) {
			ans = x.s;
			break;
		}

		// push all unvisited neighbors
		ii del[8] = { ii(1,2) , ii(1,-2) , ii(-1,2) , ii(-1,-2),
					  ii(2,1) , ii(2,-1) , ii(-2,1) , ii(-2,-1) };
		for(int i=0; i<8; i++) {
			int a = x.f.f + del[i].f;
			int b = x.f.s + del[i].s;
			int c = x.s;
			if(a < 0 || b < 0 || a >= M || b >= N)
				continue;

			if(ID[a][b] != -1)
				for(ii to : groups[ID[a][b]]) {
					if(!visited[a][b])
						Q.push(pii(to, c));
					dp[to.f][to.s] += dp[x.f.f][x.f.s];
				}
			else {
				dp[a][b] += dp[x.f.f][x.f.s];
				if(!visited[a][b])
					Q.push(pii(ii(a,b),c));
			}

			visited[a][b] = true;
		}
	}

	/*
	for(int i=0; i<M; i++)
		for(int j=0; j<N; j++)
			cout << dp[i][j] << " \n"[j==N-1];
			*/

	// output least distance
	cout << ans << endl;
	if(ans != -1)
		cout << dp[E.f][E.s] << endl;
	return 0;
}
