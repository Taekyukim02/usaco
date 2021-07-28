#include <iostream>
#include <algorithm>

using namespace std;

int N, K, A, B;
long long arr[100000];

long long dfs(long long l, long long r) {
	auto it1 = lower_bound(arr, arr+K, l);
	auto it2 = upper_bound(arr, arr+K, r);

	long long ans = (it2-it1 == 0) ? A : B*(it2-it1)*(r-l);

	long long mid = (l+r)/2;
	if(r-l == 0)
		return ans;

	return min(dfs(l, mid), dfs(mid, r));
}

int main() {
	cin >> N >> K >> A >> B;
	for(int i=0; i<K; i++) {
		cin >> arr[i];
		arr[i]--;
	}

	sort(arr, arr+K);

	cout << dfs(0, 1<<N) << endl;
}
