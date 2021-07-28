#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

struct point {
	int s;
	char t;
	int l;
	int id;
	point(int a, char b, int c, int d) {
		s = a;
		t = b;
		l = c;
		id = d;
	}
	point () {

	}
};

long long Max(long long a, long long b) {
	if(a> b)
		return a;
	return b;
}
auto cmp = [](point a, point b) {
	if(a.s != b.s)
		return a.t < b.t;
	if(a.t != b.t)
		return a.t == 'S';
	if(a.l != b.l)
		return a.l < b.l;
	return a.id < b.id;
};

int main() {
	int n, T;
	cin >> n >> T;

	point p[100000];
	int numR = 0;
	int numS = 0;
	long long startTime[100000];
	long long endTime[100000];
	for(int i=0; i<n; i++) {
		long long t;
		char a;
		long long b;
		cin >> t >> a >> b;
		if(a == 'R') 
			numR++;
		else
			numS++;

		p[i] = point(t, a, b, i);
		startTime[i] = t;
	}

	// sort p[] by what order they should be processed (if no stalling)
	sort(p, p+n, cmp);

	// go through everything
	set <point, decltype(cmp)> pres(cmp);
	set <point, decltype(cmp)> pq1(cmp);
	set <point, decltype(cmp)> pq2(cmp);

	long long i=0;
	long long latest = 0;
	while(true) {
		bool c = false;
		while( pres.size() < T && !c) {		// add more prescriptions
			cout << "ok" << endl;
			if(pq1.size() > 0) 	{		// add in-store
				point p = *pq1.begin();
				pq1.erase(pq1.begin());
				pres.insert(point(Max(p.s,latest)+p.l, p.t, p.l, p.id));
			} else if (pq2.size() > 0) {
				point p = *pq2.begin();
				pq2.erase(pq2.begin());
				pres.insert(point(Max(p.s,latest)+p.l, p.t, p.l, p.id));
			} else if (i < n) {
				if(p[i].id == 'R')
					pq2.insert(p[i]);
				else
					pq1.insert(p[i]);
				i++;
			}
			else if(i>= n)
				c = true;
		}

		if(pres.size() ==  0)
			break;

		point x = *pres.begin();
		endTime[ x.id ] = x.s;
		latest = x.s;
		pres.erase(pres.begin());
	}

	// print output
	long long totalR = 0;
	long long totalS = 0;
	for(int i=0; i<n; i++) {
		if(p[i].t == 'R') {
			totalR += endTime[ p[i].id ] - startTime[ p[i].id ];
		}
		else 
			totalS += endTime[ p[i].id ] - startTime[ p[i].id ];
	}
	cout << totalS << " " << totalR << endl;
	cout << numS << " " << numR << endl;
	cout << ((double)totalS) / numS << " " << (double)totalR / numR << endl;
}
