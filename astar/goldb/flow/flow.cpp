#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 52

using namespace std;

vector <int> connection[MAX_N];
int in[MAX_N];
int out[MAX_N];
int ans[MAX_N][MAX_N];

// remove single-node-single connections and return number removed
int single() {
	int numRemoved = 0;

	for(int i=0; i<MAX_N; i++) {
		if(in[i] == out[i] && out[i] == 1) {
			numRemoved++;
			int x = connection[i][0];
			int y = connection[i][1];
	
			if(ans[x][i] == 0) {
				x = connection[i][1];
				y = connection[i][0];
			}
			
//			cout << x << "-" << i << "-" << y << endl;

			// now we have x -> i -> y
			if(ans[x][y] == 0) {	// no previous connection exists
				ans[x][y] = min(ans[x][i], ans[i][y]);
				in[i] = out[i] = 0;
				connection[i].clear();
				ans[x][i] = ans[i][y] = 0;

				for(auto it=connection[x].begin(); it!=connection[x].end(); ++it)
					if(*it == i) {
						connection[x].erase(it);
						break;
					}
				for(auto it=connection[y].begin(); it!=connection[y].end(); ++it)
					if(*it == i) {
						connection[y].erase(it);
						break;
					}

				connection[x].push_back(y);
				connection[y].push_back(x);
/*				cout << endl;
				cout << "connected to " << x << endl;
				for(int j : connection[x])
					cout << j << " ";
				cout << "connected to " << y << endl;
				for(int j : connection[y])
					cout << j << " ";
*/					

			} else {
				ans[x][y] += min(ans[x][i], ans[i][y]);
				in[i] = out[i] = 0;
				in[y]--;
				out[x]--;
				connection[i].clear();
				ans[x][i] = ans[i][y] = 0;

				for(auto it=connection[x].begin(); it!=connection[x].end(); ++it)
					if(*it == i) {
						connection[x].erase(it);
						break;
					}
				for(auto it=connection[y].begin(); it!=connection[y].end(); ++it)
					if(*it == i) {
						connection[y].erase(it);
						break;
					}
			}

/*			// debug
			cout << "removed node " << i;
			cout << "ans["<<x<<"]["<<y<<"] = "<< ans[x][y] << endl;
			cout << endl;
*/		}
	}

	return numRemoved;
}

queue <int> tryRemove;

// remove node i and any other node that gets removed as a result.
void preprocessUtil(int i) {
	if(out[i] == 0 && i != 25) {
		// remove connections from neighbors
		for(int j : connection[i]) {
			out[j]--;
			ans[j][i] = 0;
			for(auto it=connection[j].begin(); it!=connection[j].end(); ++it)
				if(*it == i) {
					connection[j].erase(it);
					break;
				}

			if(out[j] == 0 && j != 25)
				tryRemove.push(j);
		}

		// remove the node
		in[i] = 0;
		connection[i].clear();
	}

	// remove begin-node-any     where begin != 'A'
	if(in[i] == 0 && i != 0) {
		// remove connections from neighbors
		for(int j : connection[i]) {
			in[j]--;
			ans[i][j] = 0;
			for(auto it=connection[j].begin(); it!=connection[j].end(); ++it)
				if(*it == i) {
					connection[j].erase(it);
					break;
				}

			if(in[j] == 0 && j != 25)
				tryRemove.push(j);
		}

		// remove the node
		out[i] = 0;
		connection[i].clear();
	}
}

// remove any-node-end   where end != 'Z'
void preprocess() {
	for(int i=0; i<MAX_N; i++) {
		if( (out[i] == 0 && i != 25)
				|| (in[i] == 0 && i != 0) )
			preprocessUtil(i);
		while(!tryRemove.empty()) {
			int j = tryRemove.front();
			tryRemove.pop();
			preprocessUtil(j);
		}
	}
}

int main()
{
	// read input
	int N;
	cin >> N;

	for(int i=0; i<MAX_N; i++) {
		in[i] = out[i] = 0;
		for(int j=0; j<MAX_N; j++)
			ans[i][j] = 0;
	}

	for(int i=0; i<N; i++) {
		char a, b;
		int f;
		cin >> a >> b >> f;

		int x, y;
		if(a>= 'A' && a<='Z') x = a-'A';
		else				  x = a-'a'+26;
		if(b>= 'A' && b<='Z') y = b-'A';
		else				  y = b-'a'+26;

		if(ans[x][y] == 0) {	// no previous pipe between the two
			ans[x][y] = f;
			in[y]++;
			out[x]++;
			connection[x].push_back(y);
			connection[y].push_back(x);
		} else {				// previous pipe
			ans[x][y] += f;
		}
	}

/*	// debug
	cout << endl;
	for(int i=0; i<MAX_N; i++) {
		for(int j=0; j<MAX_N; j++)
			cout << ans[i][j] << " ";
		cout << "      " << in[i] << " " << out[i] << endl;
	}
*/
	// get rid of pipes
	preprocess();

/*	cout << endl;
	for(int i=0; i<MAX_N; i++) {
		for(int j=0; j<MAX_N; j++)
			cout << ans[i][j] << " ";
		cout << "      " << in[i] << " " << out[i] << endl;
	}
*/
	while(single() > 0) {}

/*	cout << endl;
	for(int i=0; i<MAX_N; i++) {
		for(int j=0; j<MAX_N; j++)
			cout << ans[i][j] << " ";
		cout << "      " << in[i] << " " << out[i] << endl;
	}
*/	// output answer
	cout << ans[0][25] << endl;
}
