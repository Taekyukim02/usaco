#include <iostream>
#include <algorithm>
#define f first
#define s second

using namespace std;

typedef pair<int,int> ii;
typedef pair<ii, int> iii;

int T, S, N;
iii lesson[101];	// ability, start time, length
ii  track[10000];	// skill level, time


int dp[101][10001];
int best[10001];
int solve() {
	// for each lesson...
	int bestTime = 10000000;
	int nextTrack = 0;
	for(int i=0; i<=S; i++) {
		// update bestTime and nextTrack
		while(nextTrack < N && track[nextTrack].f <= lesson[i].f.f) {
			if(track[nextTrack].s < bestTime)
				bestTime = track[nextTrack].s;
			nextTrack++;
		}

		// copy best times from best[] until start of lesson
		for(int j=0; j<=lesson[i].f.s; j++)
			dp[i][j] = best[j];

		// 0 from start to end of lesson
		// ski with bestTime and update best[]
		dp[i][lesson[i].f.s + lesson[i].s] = dp[i][lesson[i].f.s];
		for(int j=lesson[i].f.s + lesson[i].s + 1; j<=T; j++) {
			if(j-bestTime >= 0) {
				dp[i][j] = max(dp[i][j-1], dp[i][j-bestTime]+1);
				best[j] = max(best[j], dp[i][j]);
			}
		}

	}
	return best[T];
}

int main() {
	// read input
	cin >> T >> S >> N;
	lesson[0] = iii( ii(1 , 1), 0);
	for(int i=1; i<=S; i++)
		cin >> lesson[i].f.s >> lesson[i].s >> lesson[i].f.f;

	for(int i=0; i<N; i++)
		cin >> track[i].f >> track[i].s;

	// sort lessons and track by ability
	sort(lesson, lesson+S);
	sort(track, track+N);

	// solve problem
	cout << solve() << endl;
	
/*	// debug
	for(int i=0; i<=S; i++) {
		for(int j=0; j<=T; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}

	for(int j=0; j<=T; j++)
		cout << best[j] << " ";
	cout << endl;
*/
	return 0;
}
