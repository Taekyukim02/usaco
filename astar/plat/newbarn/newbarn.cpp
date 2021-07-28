#include <iostream>
#include <set>
#include <queue>
#define f first
#define s second

using namespace std;

typedef pair <int,int> ii;

set <ii> points;
int N;

int calcDist(ii p) {
	long long s = 0;
	for(auto it=points.begin(); it!=points.end(); it++)
		s += abs(p.f-it->f) + abs(p.s-it->s);
	return s;
}

int getX() {
	int low = -10000;
	int high = 10000;
	while(low<high) {
		int mid = (low+high)/2;
		if(calcDist(ii(mid,0)) < calcDist(ii(mid+1,0)))
			high = mid;
		else
			low = mid+1;
	}
	return low;
}
int getY() {
	int low = -10000;
	int high = 10000;
	while(low<high) {
		int mid = (low+high)/2;
		if(calcDist(ii(0,mid)) < calcDist(ii(0,mid+1)))
			high = mid;
		else
			low = mid+1;
	}
	return low;
}

int main() {
	// read input
	cin >> N;

	for(int i=0; i<N; i++) {
		ii o;
		cin >> o.f >> o.s;
		points.insert(o);
	}	

	// binary search for best x and y
	int x = getX();
	int y = getY();

	while(points.find( ii(x,y) ) != points.end()) {
		int a = calcDist( ii(x+1, y) );
		int b = calcDist( ii(x-1, y) );
		int c = calcDist( ii(x, y+1) );
		int d = calcDist( ii(x, y-1) );

		int m = min( min(a,b), min(c,d) );
		if(a==m)
			x = x+1;
		else if(b==m)
			x = x-1;
		else if(c==m)
			y = y+1;
		else if(d==m)
			y = y-1;
	}

	bool visited[500][500];
	int count = 0;
	int dist = calcDist( ii(x,y) );
	queue <ii> bfs;
	bfs.push( ii(x,y) );
	while(!bfs.empty()) {
		ii i = bfs.front();
		bfs.pop();

		if(visited[x-i.f+250][y-i.s+250])
			continue;
		
		visited[x-i.f+250][y-i.s+250] = true;
		if(points.find( i ) == points.end())
			count++;

		if(dist == calcDist( ii(i.f+1,i.s) ) )
			bfs.emplace(x+1, y);
		if(dist == calcDist( ii(i.f-1,i.s) ) )
			bfs.emplace(x-1, y);
		if(dist == calcDist( ii(i.f,i.s+1) ) )
			bfs.emplace(x, y+1);
		if(dist == calcDist( ii(i.f,i.s-1) ) )
			bfs.emplace(x, y-1);
	}

	cout << dist << " " << count << endl;
	return 0;
}

