#include <iostream>
#include <algorithm>
#define f first
#define s second

using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,ii> pii;

auto cmp = [](pii a, pii b) {
	return a.f.s < b.f.s;
};

int main() {
	int N;
	cin >> N;
	
	set <pii> points;
	for(int i=0; i<N; i++) {
		pii x;
		cin >> x.f.f >> x.f.s >> x.s.f >> x.s.s;
		points.insert(x);
	}

	int count = 0;
	multiset <pii, decltype(cmp)> valid(cmp);
	for(auto it = points.begin(); it!=points.end(); it++)
		valid.insert(*it);

	for(auto it=points.begin(); it!=points.end(); it++) {
		pii p = *it;
		
//		cout << "p " << p.f.f << " " << p.f.s << " " << p.s.f << " " << p.s.s<< endl;
		set <pii> poss;
		for(auto ait=valid.begin(); ait!=valid.end(); ait++) {
			pii a = *ait;
			if(a == p) continue;
			if(a.f.s > p.s.s)
				break;
			if(a.s.s>=p.f.s)
				poss.insert(a);
		}
		
		bool bad = false;
		for(auto ait=poss.begin(); !bad && ait!=poss.end(); ait++) {
			pii a = *ait;
	//		cout << "try " << a.f.f << " " << a.f.s << " " << a.s.f << " " << a.s.s<< endl;
			if(a.f.f > p.s.f)
				break;
			if(a.s.f >= p.f.f)
				bad = true;
		}
	
		if(!bad) {
			count++;
	//		cout << "ok" << endl;
		}
	}

	cout << count << endl;
}
