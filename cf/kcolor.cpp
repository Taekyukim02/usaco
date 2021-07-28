#include <iostream>

using namespace std;

int visited[5001];
int ans[5000];

int main() {
	int K, N, a[5000];
	int m = -1;
	cin >> N >> K;
	for(int i=0; i<N; i++) {
		cin >> a[i];
		visited[a[i]]++;
		m = max(m, visited[a[i]]);
	}
	
	if(m > K) {
		cout << "NO" << endl;
		return 0;
	}

	int sId = -1;
	for(int i=0; i<K-m; i++) {
		ans[i] = K-i;
		visited[a[i]]--;
		if(visited[a[i]] == m-1) {
			m = -1;
			for(int j=i+1; j<N; j++)
				m = max(m, visited[a[j]]);
		}
		sId = i;
	}

	for(int i=0; i<5001; i++)
		visited[i] = false;
	for(int i=1; i<=m; i++) {
		for(int j=0; j<N; j++) {
			if(!ans[j] && !visited[a[j]]) {
				ans[j] = i;
				visited[a[j]] = true;
			}
		}
		for(int j=0; j<5001; j++)
			visited[j] = false;
	}

	cout << "YES" << endl;
	for(int i=0; i<N; i++)
		cout << ans[i] << " \n"[i==N-1];
	
	return 0;
}
