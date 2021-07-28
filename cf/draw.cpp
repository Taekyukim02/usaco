#include <iostream>

#define MAX_N 10005

using namespace std;

int N;
int A[MAX_N], B[MAX_N];

int main() {
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> A[i] >> B[i];
	
	int ans = min(A[0], B[0])+1;
	int last = min(A[0], B[0]);

	for(int i=1; i<N; i++) {
		if(min(A[i], B[i]) >= max(A[i-1], B[i-1])) {
			ans += (min(A[i], B[i]) - max(last+1, max(A[i-1], B[i-1])) + 1);
			
			last = min(A[i], B[i]);
		}
	}
	
	cout << ans << endl;
}
