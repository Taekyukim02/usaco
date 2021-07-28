#include <iostream>
#define f first
#define s second

using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,ii> pii;

int main() {
	int N;
	cin >> N;
	
	pii points[25000];
	for(int i=0; i<N; i++) {
		cin >> points[i].f.f >> points[i].f.s >> points[i].s.f >> points[i].s.s;
	}

	int count = 0;

	bool t[25000];
	for(int i=0; i<25000; i++)
		t[i] = true;

	for(int i=0; i<N; i++) {
		if(!t[i]) continue;
		pii p = points[i];
		
//		cout << "p " << p.f.f << " " << p.f.s << " " << p.s.f << " " << p.s.s<< endl;
		bool bad = false;
		for(int j = 0; j<N ; j++) {
			pii a = points[j];
			if(a == p) continue;
			if(a.f.s > p.s.s)
				continue;
			if(a.s.s < p.f.s)
				continue;
			if(a.f.f > p.s.f)
				continue;
			if(a.s.f < p.f.f)
				continue;

			bad = true;
			t[i] = false;
			break;
		}
	
		if(!bad) {
			count++;
		}
	}

	cout << count << endl;
}
