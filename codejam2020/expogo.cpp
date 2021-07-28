#include <iostream>

using namespace std;

char dir[4] = {'N', 'E', 'S', 'W'};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char cur[100];
string best;
bool foundgood;

void recurse(long long x, long long y, long long n, long long len) {
	if(n >= 200000000000 || len >= best.length()) return;

	if(x == 0 && y == 0) {
		foundgood = true;
		if(len < best.length()) {
			best = "";
			for(int i=0; i<len; i++)
				best += cur[i];
		}
	}

	if(abs(x) % n != 0 || abs(y) % n != 0)
		return;
	
	for(int t=0; t<4; t++) {
		cur[len] = dir[t];
		recurse(x - n*dx[t], y - n*dy[t], 2*n, len+1);
	}
}

void solve(long long x, long long y) {
	best = "qwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiop";
	foundgood = false;
	recurse(x, y, 1, 0);
	if(foundgood) {
		cout << best << endl;
	} else {
		cout << "IMPOSSIBLE" << endl;
	}
}

int main() {
	int T; cin >> T;
	for(int t=1; t<=T; t++) {
		long long x,y; cin >> x >> y;
		cout << "Case #" << t << ": ";
		solve(x,y);
	}
}
