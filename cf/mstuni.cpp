#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define f first
#define s second

using namespace std;

typedef pair<int,int> ii;
typedef pair<int, ii> pii;

void fastscan(int &number) 
{ 
    //variable to indicate sign of input number 
    bool negative = false; 
    register int c; 
  
    number = 0; 
  
    // extract current character from buffer 
    c = getchar(); 
    if (c=='-') 
    { 
        // number is negative 
        negative = true; 
  
        // extract the next character from the buffer 
        c = getchar(); 
    } 
  
    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
  
    // if scanned input has a negative sign, negate the 
    // value of the input number 
    if (negative) 
        number *= -1; 
} 

int N, M;
pii edges[200001];

// DSU
int par[200001];
int fPar(int n) {
	if(par[n] == n)
		return n;
	return (par[n] = fPar(par[n]));
}

int cnt = 0;
/*
int dfs(int n, bool visited[], vector<int> pGraph[]) {
	visited[n] = true;

	int sum=0;
	for(int to : pGraph[n]) {
		if(!visited[to]) {
			sum += dfs(to, visited, pGraph);
		}
	}
	return sum+1;
}
*/

int main() {
	fastscan(N);
	fastscan(M);
	for(int i=0; i<M; i++) {
		fastscan(edges[i].s.f);
		fastscan(edges[i].s.s);
		fastscan(edges[i].f);
	}
	
	sort(edges, edges+M);
	
	// build DSU
	for(int i=0; i<200001; i++)
		par[i] = i;
	
	int i=0;
	bool visited[200001];
	while(i < M) {
//		map <int, int> nodes;
//		vector <int> pGraph[200001];
		
		int j = i;
		while(edges[j].f == edges[i].f) {
			if(fPar(edges[j].s.f) != fPar(edges[j].s.s)) {
//				pGraph[fPar(edges[j].s.f)].push_back(fPar(edges[j].s.s));
//				pGraph[fPar(edges[j].s.s)].push_back(fPar(edges[j].s.f));

//				nodes[fPar(edges[j].s.f)] = 1;
//				nodes[fPar(edges[j].s.s)] = 1;
				
				cnt++;
			}
			
			j++;
		}
		
		/*
//		for(int j=1; j<=N; j++)
//			cout << par[j] << " \n"[j==N];
//		cout << "right now " << cnt << endl;
		// run dfs from each node and increment cnt for each run
		for(const auto& n : nodes)
			visited[n.f] = false;
		for(const auto& n : nodes) {
			if(!visited[n.f]) {
				// subtract # of nodes in dfs - 1
//				cout << "visiting " << n.f << endl;
				cnt -= (dfs(n.f, visited, pGraph)-1);
//				cout << cnt << endl;
			}
		}
		*/
		
		// combine dsu
		while(i < j) {
			if(fPar(edges[i].s.f) != fPar(edges[i].s.s)) {
				par[fPar(edges[i].s.f)] = fPar(edges[i].s.s);
				cnt--;
			}
			i++;
		}
//		for(int k=0; k<=N; k++)
//			cout << par[k] << " \n"[k==N];
	}
	
	cout << cnt << endl;
}
