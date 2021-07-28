#include <iostream>
#include <vector>
#include <fstream>
#define MOD 1000000007
#define MAX_N 100000

using namespace std;

struct point{
	long long a, b, c;
	point() {
		 a=b=c=0;
	}
};

long long total = 1;
vector <vector<int> > path(MAX_N+1, vector<int> (0));
vector <point> colors(MAX_N+1, point());

long long expo(long long i, long long e) {
	long long ret;
	if(e==0) ret =  1;
	else if(e==1) ret =  i;
	else if(e%2 == 1) ret = i * expo(i*i % MOD, (e-1)/2) % MOD;
	else 		ret = expo(i*i % MOD, e/2) % MOD;

//	cout << "ret " << ret << endl;
	return ret;
}

long long inverse (long long i) {
	return expo(i, MOD-2);
}

void dfs(int node, int par) {
//	cout << "node " << node << " par " << par << endl;
	vector <int> next;
	for(int x : path[node])
		if(x != par) {
			if(colors[x].a || colors[x].b || colors[x].c) {
				if(colors[x].a == 1) colors[node].a = 0;
				if(colors[x].b == 1) colors[node].b = 0;
				if(colors[x].c == 1) colors[node].c = 0;
				dfs(x, node);
			}
			else next.push_back(x);
		}
	
	if(next.empty()) {
		total = (colors[node].a + colors[node].b + colors[node].c)
					* total % MOD;
//		cout << "new " << total << endl;
//		cout << "node " << node << endl;
	}
	else {
		for(int x : next) {
			colors[x].a = colors[node].b + colors[node].c;
			colors[x].b = colors[node].a + colors[node].c;
			colors[x].c = colors[node].a + colors[node].b;
			dfs(x, node);
		}
//		cout << "sum " << colors[node].a + colors[node].b + colors[node].c << endl;
//		cout << "inv " <<inverse(colors[node].a + colors[node].b + colors[node].c) << endl;
		total = total * inverse(colors[node].a + colors[node].b + colors[node].c) % MOD;
	}
}

int main() {
	ifstream fin ("barnpainting.in");
	ofstream fout ("barnpainting.out");

	int N, K;
	fin >> N >> K;

	for(int i=0; i<N-1; i++) {
		int a, b;
		fin >> a >> b;
		path[a].push_back(b);
		path[b].push_back(a);
	}
	
	for(int i=0; i<K; i++) {
		int x, y;
		fin >> x >> y;
		if(y==1) colors[x].a = 1;
		if(y==2) colors[x].b = 1;
		if(y==3) colors[x].c = 1;
	}
	
//  for(int i=1; i<=N; i++) {
//  	for(int x : path[i])
//  		cout << x << " ";
//  	cout << endl;
//  }
	// dfs
	colors[1].a = colors[1].b = colors[1].c = 1;
	dfs(1, -1);

	fout << total << endl;
	return 0;
}
