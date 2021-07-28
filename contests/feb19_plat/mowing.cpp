#include <iostream>
#include <algorithm>
#include <fstream>
#include <stack>

#define f first
#define s second
#define MAX_N 200000

using namespace std;

typedef pair <long long, long long> ii;

int N, T;
ii points[MAX_N+5];
ii dp[MAX_N+5];
bool solved[MAX_N+5];
long long jumpTo[MAX_N+5];

ii solve(long long idx) {
	if(idx == N+1)
		return ii(0, 0);
	
	if(solved[idx])
		return dp[idx];
	
	ii best = ii(987654321, -1);
	long long lowY = 987654321;
	long long start = idx+1;
	while(start != N+2 && points[start].s > points[idx].s)
		start++;

	for(int i=start; i != N+2; i = jumpTo[i]) {
		ii ret = solve(i);
		long long area = (points[i].f-points[idx].f)*(points[i].s-points[idx].s);
		if(ret.s+1 > best.s
			|| (ret.s+1 == best.s && ret.f+area < best.f))
			best = ii(ret.f+area, ret.s+1);
	}

	solved[idx] = true;
//	cout << "at " << idx << " " << points[idx].f << " " << points[idx].s << " " << best.f << " " << best.s << endl;
	return dp[idx] = best;
}

int main() {
	ifstream fin ("mowing.in");
	fin >> N >> T;
	for(int i=0; i<N; i++)
		fin >> points[i].f >> points[i].s;
	fin.close();

	points[N] = ii(T, T);
	points[N+1] = ii(0, 0);

	sort(points, points+N+2);

	// create jumpTo
	stack <ii> st;
	st.push(ii(-1, N+2));
	for(int i=N+1; i>=0; i--) {
		while(st.top().f >= points[i].s)
			st.pop();
		jumpTo[i] = st.top().s;
		st.push(ii(points[i].s, i));
	}

	for(int i=0; i<N+2; i++)
		cout << jumpTo[i] << endl;
/*
cout << endl;
cout << N << endl;
	for(int i=0; i<N+2; i++)
		cout << i << " " <<points[i].f << " " << points[i].s << endl;

		cout << endl;
		*/
	
	ofstream fout ("mowing.out");
	fout << solve(0).f << endl;
	fout.close();
}
