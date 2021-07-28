#include <iostream>
#include <map>
#include <queue>
#define MOD 998244353

using namespace std;

int main() {
	int N, a[200000];
	map <int, int> last;
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> a[i];
		last[a[i]] = i;
	}
	
	long long ans = 1;
	priority_queue <int> out;
	out.push(-last[a[0]]);
	for(int i=1; i<N; i++) {
		while(!out.empty() && -out.top() < i)
			out.pop();

		if(out.empty())
			ans = (ans*2)%MOD;

		out.push(-last[a[i]]);
	}
	
	cout << ans << endl;
}

