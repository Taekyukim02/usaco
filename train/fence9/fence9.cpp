/*
ID: taekyuk1
TASK: fence9
LANG: C++
*/
#include <iostream>
#include <fstream>
#define f first
#define s second

using namespace std;

typedef pair<double,double> ii;

int N, M, P;

int ccw(ii a, ii b) {
	double cal = a.f*b.s - a.s*b.f;
	double e = 0.0000001;
	if(cal < e && cal > -e) return 0;
	if(cal < e) return -1;
	return 1;
}

bool ss(ii p, ii q, ii a, ii b) {
	ii pa = ii(p.f-a.f, p.s-a.s);
	ii pb = ii(p.f-b.f, p.s-b.s);
	ii pq = ii(p.f-q.f, p.s-q.s);

	if(ccw(pa, pq) != 0 && ccw(pa, pq) == ccw(pb, pq))
		return true;
	return false;
}

bool inside(ii a, ii b) {
	ii x = ii(N, M);
	ii y = ii(0, 0);
	ii z = ii(P, 0);

	if(ss(x, y, a, b)
		&& ss(y, z, a, b)
		&& ss(x, z, a, b))
		return true;
	return false;
}

int main() {
	ifstream fin ("fence9.in");
	fin >> N >> M >> P;
	fin.close();

	int cnt = 0;
	double s1 = (N==0) ? 987654321.0 : (double) M / N;
	double s2 = (N==P) ? 987654321.0 : (double) M / (N-P);
//	cout << s1 << " " << s2 << endl;
	for(int i=1; i<max(N, P); i++) {
		int low = 1;
		if(s2 > 0)
			low = max(1, (int) (s2*(i-P)+1));
		int high;
		if(i <= N)
			high = (int) (s1*i-0.0000001);
		else
			high = (int) (s2*(i-P)-0.000001);
//		cout << i << "  low " << low << "  high " << high << endl;

		cnt += max((high-low+1), 0);
	}
	/*
	ii center = ii(((double) N+P)/3, ((double) M)/3);

	for(int i=1; i<=max(N, P); i++) {
		bool found = false;
		for(int j=1; j<=32000; j++) {
			//cout << i << " " << j << endl;
			if(inside(ii(i,j), center)) {
				cnt++;
				found = true;
			}
			else if(found)
				break;
		}
	}
	*/

	ofstream fout ("fence9.out");
	fout << cnt << endl;
	fout.close();
}
