#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int,int> ii;

int segtree[600000];
int N, M;

int getUtil(int l, int r, int q1, int q2, int n) {
	if(l>r || r<q1 || l>q2 || q2<q1) return -1;
	if(l==r) return segtree[n];;

	int mid = (l+r)/2;
	return max( getUtil(l,mid,q1,q2,2*n), getUtil(mid+1,r,q1,q2,2*n+1));
}

int getMax(int l, int r) {
	return getUtil(0, N+1, l, r, 1);
}

void updateUtil(int l, int r, int pos, int v, int n) {
	if(pos<l || pos>r) return;
	
	if(l==r) {
		segtree[n] = v;
		return;
	}
	int mid = (l+r)/2;
	updateUtil(l,mid,pos,v,2*n);
	updateUtil(mid+1,r,pos,v,2*n+1);
	segtree[n] = max(segtree[2*n], segtree[2*n+1]);
}

void update(int i, int v) {
	updateUtil(0, N+1, i, v, 1);
}

int main() {
	ii leftArr[100000], rightArr[100000];
	cin >> N >> M;
	for(int i=0; i<M; i++) {
		int a, b;
		cin >> a >> b;
		leftArr[i] = ii(a,b);
		rightArr[i] = ii(b,a);
	}
	
	sort(leftArr, leftArr+M);
	sort(rightArr, rightArr+M);

	int maxOut = 0;			// right-most point of left endpoints 
								// of intervals not including current cow
	map <int,int> in;			// set of left endpoints of "in" intervals
	int leftIt = 0;
	int rightIt = 0;
	int dp = 0;
	for(int i=1; i<=N+1; i++) {
		// add intervals into "in" map
		while(leftIt < M && leftArr[leftIt].first <= i) {
			if(in.find(leftArr[leftIt].first) != in.end())
				in[leftArr[leftIt].first]++;
			else
				in[leftArr[leftIt].first] = 1;

			leftIt++;
		}

		// remove intervals from "in" map and update maxOut
		while(rightIt < M && rightArr[rightIt].first < i) {
			if(in[rightArr[rightIt].second] > 1)
				in[rightArr[rightIt].second]--;
			else
				in.erase(rightArr[rightIt].second);

			maxOut = max(rightArr[rightIt].second, maxOut);
//			cout << "maxOut: " << maxOut << endl;
			rightIt++;
		}

		// query for max dp in appropriate interval
//		cout << "size: " << in.size() << endl;
		int l = maxOut;
		int r = i-1;
		if(!in.empty())
			r = in.begin()->first -1;
		dp = getMax(l, r)+1;
		update(i, dp);
	}
//	for(int i=0; i<=N; i++)
//		cout << dp[i] << endl;
	cout << dp-1 << endl;
}
