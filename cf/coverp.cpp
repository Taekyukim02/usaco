#include <iostream>
#include <algorithm>
#include <queue>
#define f first
#define s second

using namespace std;

typedef pair<long long, long long> ii;

long long cnt[200005], N;
ii arr[400010];

int main() {
	cin >> N;
	for(int i=0, j=1; i<2*N;) {
		long long a, b;
		cin >> a >> b;
		arr[i++] = ii(a, -1);
		arr[i++] = ii(b, 1);
		cnt[j++] = 0;
	}
	
	sort(arr, arr+2*N);

	int curr = 0;
	for(int i=0; i<2*N; ) {
		long long x = arr[i].f;

		// process in
		while(arr[i].f == x && arr[i].s != 1) {
			curr++;
			i++;
		}

		// add curr to cnt
		cnt[curr]++;

		// process out
		while(i<2*N && arr[i].f == x) {
			curr--;
			i++;
		}

		// consider cnt from x+1 to arr[i].f-1
		if(i < 2*N && x+1 <= arr[i].f-1)
			cnt[curr] += (arr[i].f-1)-(x+1)+1;
	}

	for(int i=1; i<=N; i++)
		cout << cnt[i] << " \n"[i==N];
	
	return 0;
}
