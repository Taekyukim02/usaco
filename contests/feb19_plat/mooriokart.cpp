#include <iostream>
#include <fstream>
#include <vector>

#define MAX_N 1000
#define MAX_Y 1000
#define f first
#define s second
#define MOD 1000000007ll

using namespace std;

typedef pair <long long, long long> ii;

int N, M, X, Y;
vector <ii> graph[MAX_N+5];
vector <int> tree[MAX_N+5];

long long sum[MAX_N+5], num[MAX_N+5];
long long dp[MAX_N+5][MAX_N+5];
bool visited[MAX_N+5];

// build trees
void dfs(int n, int i) {
	visited[n] = true;
	tree[i].push_back(n);
	for(ii to : graph[n])
		if(!visited[to.f])
			dfs(to.f, i);
}

void addLength(int node, int par, int len, int i) {
	if(len != 0) {
		if(len+X < Y)
			dp[i][len+X]++;
		else {
			sum[i] = (sum[i]+len+X)%MOD;
			num[i]++;
		}
	}

	for(ii to : graph[node]) {
		if(to.f != par) {
			addLength(to.f, node, len+to.s, i);
		}
	}
}

long long expo(long long a, long long b) {
	if(b==0) return 1;
	if(b==1) return a;
	if(b%2) return a*expo(a*a%MOD, b/2)%MOD;
	return expo(a*a%MOD, b/2);
}

int main() {
	// read input
	ifstream fin ("mooriokart.in");
	fin >> N >> M >> X >> Y;
	for(int i=0; i<M; i++) {
		int a, b, c;
		fin >> a >> b >> c;
		graph[a-1].push_back(ii(b-1, c));
		graph[b-1].push_back(ii(a-1, c));
	}
	fin.close();

	// find trees
	int K=0;
	for(int i=0; i<N; i++)
		if(!visited[i]) {
			dfs(i, K);
			K++;
		}
	
	// get path lengths in each tree
	for(int i=0; i<K; i++) {
		for(int j : tree[i])
			addLength(j, -1, 0, i);
		for(int j=0; j<Y; j++)
			dp[i][j] /= 2;
		sum[i] = (sum[i] * expo(2, MOD-2)) % MOD;		// TODO
		num[i] /= 2;
	}

/*
	// debug
    cout << "K " << K << endl;
	for(int i=0; i<K; i++)
		for(int j=0; j<Y; j++)
			cout << dp[i][j] << " \n"[j==Y-1];
	
	for(int i=0; i<K; i++)
		cout << sum[i] << " \n"[i==K-1];
	for(int i=0; i<K; i++)
		cout << num[i] << " \n"[i==K-1];
	cout << endl;
	*/

	// iterate through trees and get all possible combinations of lengths
	for(int i=0; i<K-1; i++) {
		long long newDp[MAX_N+5], newSum=0, newNum=0;
		for(int j=0; j<Y; j++)
			newDp[j] = 0;

		for(int a=0; a<Y; a++)
			for(int b=0; b<Y; b++) {
				if(a+b < Y) {
					newDp[a+b] += dp[i][a]*dp[i+1][b];
					newDp[a+b] %= MOD;
				}
				else {
					newSum += (a+b)*dp[i][a]*dp[i+1][b];
					newSum %= MOD;
					newNum += dp[i][a]*dp[i+1][b];
					newNum %= MOD;
				}
			}

		if(sum[i] > 0)
			for(int a=0; a<Y; a++) {
				newSum = (newSum + dp[i+1][a]*(a+sum[i]))%MOD;
				newSum %= MOD;
				newNum += dp[i][a]*num[i];
				newNum %= MOD;
			}
		if(sum[i+1] > 0)
			for(int a=0; a<Y; a++) {
				newSum = (newSum + dp[i][a]*(a+sum[i+1]))%MOD;
				newSum %= MOD;
				newNum += dp[i+1][a]*num[i+1];
				newNum %= MOD;
			}

		newSum += num[i]*sum[i+1] + num[i+1]*sum[i];
		newSum %= MOD;
		newNum += num[i]*num[i+1];
		newNum %= MOD;


		for(int j=0; j<Y; j++)
			dp[i+1][j] = newDp[j]%MOD;
		sum[i+1] = newSum%MOD;
		num[i+1] = newNum%MOD;
		
		/*
    cout << "K " << K << endl;
	for(int i=0; i<K; i++)
		for(int j=0; j<Y; j++)
			cout << dp[i][j] << " \n"[j==Y-1];
	
	for(int i=0; i<K; i++)
		cout << sum[i] << " \n"[i==K-1];
	for(int i=0; i<K; i++)
		cout << num[i] << " \n"[i==K-1];
	cout << endl;
	*/
	}

/*
	for(int j=0; j<Y; j++)
		cout << dp[K-1][j] << " \n"[j==Y-1];
	
	cout << sum[K-1] << " \n";
	*/

	// output last sum * 2^(K-1) * (K-1)!
	long long ans = sum[K-1]%MOD;
	for(int i=1; i<K; i++)
		ans = (ans*2*i)%MOD;


	ofstream fout ("mooriokart.out");
	fout << ans << endl;
	fout.close();
	return 0;
}
