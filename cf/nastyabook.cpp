#include <iostream>

using namespace std;

int N, K;
int arr1[105], arr2[105];

int main() {
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> arr1[i] >> arr2[i];
	cin >> K;
	
	int ans=0;
	while(ans < N && K-1 >= arr2[ans])
		ans++;

	cout << N-ans << endl;
}
