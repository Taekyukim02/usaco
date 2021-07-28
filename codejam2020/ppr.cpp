#include <iostream>
#include <algorithm>
#define MAX_N 1010
#define f first
#define s second

using namespace std;

typedef pair<int,int> ii;
typedef pair<ii, int> iii;

iii pts[2*MAX_N];

int main() {
	int T;	cin >> T;
	for(int t=1; t<=T; t++) {
		int N;	cin >> N;
		char assigned[MAX_N];
		bool possible = true;
		for(int i=0; i<N; i++) {
			cin >> pts[2*i].f.f >> pts[2*i+1].f.f;
			pts[2*i].f.s = 1;
			pts[2*i+1].f.s = 0;
			pts[2*i].s = pts[2*i+1].s = i;
		}
		sort(pts, pts+2*N);
		/*
		for(int i=0; i<2*N; i++) {
			cout << pts[i].f.f << " " << pts[i].f.s << " " << pts[i].s << endl;
		}*/

		bool opp[2] = {0, 0};
		for(int i=0; i<2*N; i++) {
			if(pts[i].f.s == 0) {
				char c = assigned[pts[i].s];
				if(c == 'C') opp[0] = 0;
				if(c == 'J') opp[1] = 0;
			}

			if(pts[i].f.s == 1 && opp[0] == false) {
				assigned[pts[i].s] = 'C';
				opp[0] = true;
			} else if(pts[i].f.s == 1 && opp[1] == false) {
				assigned[pts[i].s] = 'J';
				opp[1] = true;
			} else if(pts[i].f.s == 1) {
				possible = false;
				break;
			}
		}

		cout << "Case #" << t << ": ";
		if(possible) {
			for(int i=0; i<N; i++)
				cout << assigned[i];
			cout << endl;
		} else {
			cout << "IMPOSSIBLE" << endl;
		}
	}
}
