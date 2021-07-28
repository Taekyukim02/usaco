#include <iostream>
#include <fstream>
#include <set>
#define f first
#define s second

using namespace std;

typedef pair<int,int> ii;

int N, K;
string dist;
int dp[100001];
int preG[100001];

set <ii> S;
int zero = 0;
int p1 = 0;
int M;
void create(int j) {
	M = dp[p1];
	S.clear();
	zero = 0;
	if(p1 == 0)
		S.insert(ii(0, -1));
	while(dp[p1] == M && p1 < j) {
		if(p1 == 0)
			S.insert(ii( 2*(preG[j]) - (j-p1), p1) );
		else
			S.insert(ii( 2*(preG[j]-preG[p1-1]) - (j-p1), p1) );
		p1++;
	}
}

void add(int i) {
	S.insert(ii(zero, i));
	p1++;
}

int get(int j) {
	while(!S.empty()) {
		auto it = S.begin();
		ii x = *it;
		if(x.s + K < j) {
			S.erase(it);
			continue;
		}
		if(x.f < zero)
			return 0;
		return 1;
	}
	create(j);
	return 1+get(j);
}

int main() {
	ifstream fin ("redistrict.in");
	fin >> N >> K;
	fin >> dist;
	fin.close();

	preG[0] = (dist[0] == 'G');
	for(int i=1; i<N; i++)
		preG[i] = preG[i-1] + (dist[i] == 'G');
	
	for(int i=0; i<N; i++) {
		if(S.empty()) create(i);		
		zero = (zero+1 - 2*('G' == dist[i]));

		if(i == 0)
			dp[i] = (dist[0] == 'G');
		else {
			dp[i] = M + get(i);
		}

/*
		cout << "i " << i << "  p1 " << p1 << "  M " << M << "  zero " << zero << endl;
		for(auto it=S.begin(); it != S.end(); it++)
			cout << "S: " << it->f << " " << it->s << endl;
		cout << "dp: ";
		for(int j=0; j<N; j++)
			cout << dp[j] << " \n"[j==N-1];
			*/

		if(dp[i] == M && p1 < dp[i])
			add(i);
	}

	ofstream fout ("redistricting.out");
	fout << dp[N-1] << endl;
	fout.close();
}
